
//
// Created by 沈星宇 on 2021/3/24.
//

#ifndef INC_2_6__MAZE_H
#define INC_2_6__MAZE_H

#include "Stack.h"

typedef struct {
    int data[100][100];       //0 wall 1 way
    Pos entry, exit;          //entry pos, exit pos
    int isVisited[100][100];  //visit mark
    int row, col;             //size of maze
} Maze;

void MazeInit(Maze *maze) {
    printf("Input: size of maze, entry pos, exit pos.\n");
    scanf("%d%d", &maze->row, &maze->col);
    scanf("%d%d", &maze->entry.row, &maze->entry.col);
    scanf("%d%d", &maze->exit.row, &maze->exit.col);
    for (int i = 0; i < maze->row; i++) {
        for (int j = 0; j < maze->col; j++) {
            scanf("%d", &maze->data[i][j]);
            maze->isVisited[i][j] = 0;
        }
    }
}


int getPath(Maze *maze, Pos pos, Stack **s) {
    if (!PosCmp(pos, maze->exit)) {//found the solution
        return 0;
    } else {
        Pos nPos[4];
        for (int i = 0; i < 4; i++) {
            PosCopy(&nPos[i], &pos);
        }
        nPos[0].row--;
        nPos[1].row++;
        nPos[2].col--;
        nPos[3].col++;
        for (int i = 0; i < 4; ++i) {
            /*within the range and not visited and not dead end*/
            if (nPos[i].row >= 0 && nPos[i].row < maze->row && nPos[i].col >= 0 && nPos[i].col < maze->col &&
                maze->data[nPos[i].row][nPos[i].col] == 1 &&
                maze->isVisited[nPos[i].row][nPos[i].col] == 0) {
                maze->isVisited[nPos[i].row][nPos[i].col] = 1;
                if (getPath(maze, nPos[i], s) == 0) {
                    StackPush(s, nPos[i]);//push pos on route into stack
                    return 0;
                }
                maze->isVisited[nPos[i].row][nPos[i].col] = 0;
            }
        }
        return -1;
    }
}

int MazePath(Maze maze) {
    Pos pos;
    Stack *s;
    int numOfPath;
    int minLenOfPath = 0;
    s = StackInit();
    PosCopy(&pos, &maze.entry);
    maze.isVisited[pos.row][pos.col] = 1;
    if (getPath(&maze, pos, &s) == 0) {
        printf("Maze has at least 1 path.\n");
        printf("One of the possible route is:\n");
        int path[100][100] = {0};
        for (int i = 0; i < maze.row; ++i) {
            for (int j = 0; j < maze.col; ++j) {
                path[i][j] = 0;
            }
        }
        while (StackIsEmpty(*s) == 0) {
            StackPop(&s, &pos);
            path[pos.row][pos.col] = 1;
        }
        path[maze.entry.row][maze.entry.col] = 1;
        int i, j;
        for (i = 0; i < maze.row; ++i) {
            for (j = 0; j < maze.col - 1; ++j) {
                printf("%d ", path[i][j]);
            }
            printf("%d\n", path[i][j]);
        }

//        printf("Entry->\n");
//        StackPop(&s, &pos);
//        int i = 0;
//        while (StackIsEmpty(*s) == 0) {
//            StackPop(&s, &pos);
//            if (i < 4) {
//                printf("(%d,%d)->", pos.row, pos.col);
//                i++;
//            } else {
//                printf("(%d,%d)->\n", pos.row, pos.col);
//                i = 0;
//            }
//        }
//        printf("\nExit\n");
//        return 0;
    } else {
        printf("Maze does not have path.\n");
        return -1;
    }
}

#endif //INC_2_6__MAZE_H

