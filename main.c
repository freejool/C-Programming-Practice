#include "snake.h"

//
// Created by Sxing on 04/28/2021.
//

int main() {
    srand((unsigned int) time(0));
    int end = 1;
    int result;
    while (end) {
        result = menu();
        switch (result) {
            case 1:
                initMap();
                while (moveSnake());
                break;
            case 2:
                help();
                break;
            case 3:
                about();
                break;
            case 0:
                end = 0;
                break;
        }
    }


    return 0;
}
