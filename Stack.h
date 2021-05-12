//
// Created by 沈星宇 on 2021/3/24.
//

#ifndef INC_2_6__STACK_H
#define INC_2_6__STACK_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int row, col;
} Pos;

void PosCopy(Pos *pos1, Pos *pos2) {
    pos1->row = pos2->row;
    pos1->col = pos2->col;
}

int PosCmp(Pos pos1, Pos pos2) {
    if (pos1.row == pos2.row && pos1.col == pos2.col) {
        return 0;
    } else {
        return -1;
    }
}

typedef struct Node {
    Pos pixel;
    struct Node *next;
} Stack;

Stack *StackInit() {
    Stack *s;
    if ((s = (Stack *) malloc(sizeof(Stack))) == NULL) {
        return NULL;
    }
    s->next=NULL;
    return s;
}

//when empty return 1
int StackIsEmpty(Stack s) {
    if (s.next == NULL) {
        return 1;
    } else
        return 0;
}

int StackGetTop(Stack s, Pos *pos) {
    if (s.next == NULL) {
        printf("ERROR! Stack is empty.\n");
        return -1;
    } else {
        PosCopy(pos, &s.pixel);
        return 0;
    }
}

int StackPush(Stack **s, Pos x) {
    Stack *p;
    if ((p = (Stack *) malloc(sizeof(Stack))) == NULL) {
        return -1;
    }
    PosCopy(&p->pixel, &x);
    p->next = *s;
    *s = p;
    return 0;
}

int StackPop(Stack **s, Pos *e)
{
    Stack *p;
    if ((*s)->next == NULL)
    {
        printf("ERROR! Stack is Empty.\n");
        return -1;
    }
    p = *s;
    PosCopy(e, &(*s)->pixel);
    *s = (*s)->next;
    free(p);
    return 0;
}




#endif //INC_2_6__STACK_H
