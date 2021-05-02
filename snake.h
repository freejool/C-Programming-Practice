#pragma once
//
// Created by Sxing on 04/28/2021.
//




#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>

#define MAP_HEIGHT 20
#define MAP_WIDTH 40
#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'


typedef struct {
    int x;
    int y;
} Food, SnakeNode;

typedef struct {
    SnakeNode snake_body[1000];
    int length;
    int speed;
} Snake;

Snake snake;
Food food;

char nowDir = RIGHT;
char dir = RIGHT;

void gotoXY(int x, int y);       // 光标定位
void hide();                // 隐藏光标
int menu();                 // 主菜单
void help();                // 帮助信息
void about();               // 关于信息
void initMap();             // 地图初始化
void printFood();           // 生成食物
int moveSnake();            // 蛇移动
int isCorrect();            // 是否撞墙或自撞
void speedControl();        // 速度控制


int menu() {
    gotoXY(40, 12);
    printf("Welcome to SNAKE!");
    gotoXY(43, 14);
    printf("1. Start");
    gotoXY(43, 16);
    printf("2. Help");
    gotoXY(43, 18);
    printf("3. About");
    gotoXY(43, 20);
    printf("Press any other key to quit");
    hide();
    char ch;
    int result = 0;
    ch = _getch(); // get input from keyboard
    switch (ch) {
        case '1':
            result = 1;
            break;
        case '2':
            result = 2;
            break;
        case '3':
            result = 3;
            break;
    }
    system("cls");
    return result;
}

void gotoXY(int x, int y) {
    HANDLE hout;
    COORD cor;
    hout = GetStdHandle(STD_OUTPUT_HANDLE);
    cor.X = x;
    cor.Y = y;
    SetConsoleCursorPosition(hout, cor);
}

void hide() {
    HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cor_info = {1, 0};
    SetConsoleCursorInfo(hout, &cor_info);
}

void about() {
    gotoXY(20, 12);
    printf("By Sxing from HDU on 04/30/2021");
    gotoXY(20, 14);
    printf("SNAKE");
    gotoXY(20, 16);
    printf("Press any key to return");
    hide();
    char ch = _getch();
    system("cls");
}

void help() {
    gotoXY(20, 12);
    printf("W UP");
    gotoXY(20, 14);
    printf("S DOWN");
    gotoXY(20, 16);
    printf("A LEFT");
    gotoXY(20, 18);
    printf("D RIGHT");
    gotoXY(20, 20);
    printf("DO NOT let your head hit boundaries or your body");
    gotoXY(20, 22);
    printf("Press any key to return");
    hide();
    char ch = _getch();
    system("cls");
}

void initMap() {
    hide();
    snake.snake_body[0].x = MAP_WIDTH / 2 - 1;
    snake.snake_body[0].y = MAP_HEIGHT / 2 - 1;
    gotoXY(snake.snake_body[0].x, snake.snake_body[0].y);
    printf("@");
    snake.length = 3;
    snake.speed = 250;
    nowDir = RIGHT;

    for (int i = 1; i < snake.length; ++i) {
        snake.snake_body[i].y = snake.snake_body[i - 1].y;
        snake.snake_body[i].x = snake.snake_body[i - 1].x - 1;
        gotoXY(snake.snake_body[i].x, snake.snake_body[i].y);
        printf("o");
    }

    for (int i = 0; i < MAP_WIDTH; ++i) {
        gotoXY(i, 0);
        printf("-");
        gotoXY(i, MAP_HEIGHT - 1);
        printf("-");
    }

    for (int i = 0; i < MAP_HEIGHT; ++i) {
        gotoXY(0, i);
        printf("|");
        gotoXY(MAP_WIDTH - 1, i);
        printf("|");
    }

    printFood();
    gotoXY(5, 25);
    printf("Score: 0");
}

void printFood() {
    int flag = 1;
    while (flag) {
        flag = 0;
        food.x = rand() % (MAP_WIDTH - 2) + 1;
        food.y = rand() % (MAP_HEIGHT - 2) + 1;
        for (int i = 0; i < snake.length - 1; ++i) {
            if (snake.snake_body[i].x == food.x && snake.snake_body[i].y == food.y) {
                flag = 1;
                break;
            }
        }
    }
    gotoXY(food.x, food.y);
    printf("$");
}

int moveSnake() {
    SnakeNode tmp;
    int flag = 0;
    tmp = snake.snake_body[snake.length - 1];
    for (int i = snake.length - 1; i >= 1; --i) {
        snake.snake_body[i] = snake.snake_body[i - 1];
    }
    gotoXY(snake.snake_body[1].x, snake.snake_body[1].y);
    printf("o");

    if (_kbhit()) {
        dir = _getch();
        switch (dir) {
            case UP:
                if (nowDir != DOWN) {
                    nowDir = dir;
                }
                break;
            case DOWN:
                if (nowDir != UP) {
                    nowDir = dir;
                }
                break;
            case LEFT:
                if (nowDir != RIGHT) {
                    nowDir = dir;
                }
                break;
            case RIGHT:
                if (nowDir != LEFT) {
                    nowDir = dir;
                }
                break;

            case -32: // arrow control
                switch (_getch()) {
                    case 72:
                        if (nowDir != DOWN) {
                            nowDir = UP;
                        }
                        break;
                    case 80:
                        if (nowDir != UP) {
                            nowDir = DOWN;
                        }
                        break;
                    case 75:
                        if (nowDir != RIGHT) {
                            nowDir = LEFT;
                        }
                        break;
                    case 77:
                        if (nowDir != LEFT) {
                            nowDir = RIGHT;
                        }
                        break;
                }

        }
    }
    switch (nowDir) {
        case UP:
            snake.snake_body[0].y--;
            break;
        case DOWN:
            snake.snake_body[0].y++;
            break;
        case LEFT:
            snake.snake_body[0].x--;
            break;
        case RIGHT:
            snake.snake_body[0].x++;
            break;
    }
    gotoXY(snake.snake_body[0].x, snake.snake_body[0].y);
    printf("@");

    // 判断是否吃到食物
    if (snake.snake_body[0].x == food.x && snake.snake_body[0].y == food.y) {
        snake.length++;
        flag = 1;
        snake.snake_body[snake.length - 1] = tmp;
    }

    // 没吃到食物
    if (!flag) {
        gotoXY(tmp.x, tmp.y);
        printf(" "); // over print the tail
    } else {
        printFood();
        gotoXY(5, 25);
        printf("Score: %d", snake.length - 3); // refresh score
    }

    // 判断死亡
    if (!isCorrect()) {
        system("cls");
        gotoXY(20, 14);
        printf("Your score: %d", snake.length - 3);
        gotoXY(20, 16);
        printf("GAME OVER!");
        gotoXY(20, 18);
        printf("Press any key to return");
        char c = _getch();
        system("cls");
        return 0;
    }

    speedControl();
    Sleep(snake.speed);
    return 1;
}


int isCorrect() {
    if (snake.snake_body[0].x == 0 || snake.snake_body[0].y == 0 || snake.snake_body[0].x == MAP_WIDTH - 1 ||
        snake.snake_body[0].y == MAP_HEIGHT - 1) {
        return 0;
    }
    for (int i = 1; i < snake.length; ++i) {
        if (snake.snake_body[0].x == snake.snake_body[i].x && snake.snake_body[0].y == snake.snake_body[i].y) {
            return 0;
        }

    }
    return 1;
}

void speedControl() {
    switch (snake.length) {
        case 6:
            snake.speed = 100;
            break;
        case 9:
            snake.speed = 180;
            break;
        case 12:
            snake.speed = 160;
            break;
        case 15:
            snake.speed = 140;
            break;
        case 18:
            snake.speed = 120;
            break;
        case 21:
            snake.speed = 100;
            break;
        case 24:
            snake.speed = 80;
            break;
        case 27:
            snake.speed = 60;
            break;
        case 30:
            snake.speed = 40;
            break;
    }
}


