//
// Created by Sxing on 03/07/2021.
//

#ifndef INC_1__WORDSPLIT_H
#define INC_1__WORDSPLIT_H

#endif //INC_1__WORDSPLIT_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define lenOfWord 40
#define numOfRem 24 //num of removing word
#define numOfPunc 4

const char rem[][lenOfWord] = {"with", "in", "one", "we", "a", "to", "and", "an", "has", "been", "the", "this", "is",
                               "as", "that", "for", "be", "can", "than", "are", "by", "at", "of", "from"};
const char punctuation[numOfPunc] = ",.?!";


typedef enum {
    false, true
} bool;

typedef struct node {
    char word[lenOfWord];
    unsigned int freq;
    double cent;
    struct node *next;
} node, *pnode;

typedef struct linkedList {
    pnode head;
    unsigned int count;
    //int maxLen;
} linkedList;

pnode locate(linkedList *L, char ch[]) {
    pnode p = L->head;
    while (p != NULL) {
        if (strcmp(p->word, ch) == 0) {
            return p;
        }
        p = p->next;
    }
    return NULL;
} //return NULL when not found, location when found

bool isRem(char ch[]) {
    bool isRem = false;
    for (int i = 0; i < numOfRem;
         i++) {
        if (strcmp(ch, rem[i]) == 0) {
            isRem = true;
            break;
        }
    }
    return isRem;
}

//Punctuation
void deCasePunc(char *ch) {
    for (int i = 0; i < strlen(ch); i++)
        if (ch[i] >= 65 && ch[i] <= 90) {
            ch[i] += 32;
        }
    char *lastC = &ch[strlen(ch) - 1];
    for (int i = 0; i < numOfPunc; i++) {
        if (*lastC == punctuation[i]) {
            *lastC = '\0';
            break;
        }
    }
}

void addEnd(pnode pTail, char ch[]) {
    pTail->next = (pnode) malloc(sizeof(node));
    if (pTail->next == NULL) {
        printf("ERROR! Out of memory!\n");
        exit(-1);
    }
    strcpy(pTail->next->word, ch);
    pTail->next->freq = 1;
    pTail->next->next = NULL;
}

void initLlist(linkedList *L, FILE *fpR) {
    L->head = (pnode) malloc(sizeof(node));
    if (L->head == NULL) {
        printf("ERROR! Out of memory!\n");
        exit(-1);
    }
    L->head->word[0] = '\0';
    L->head->freq = 0;
    L->head->next = NULL;
    L->count = 0;
    char ch[40];
    pnode pTail = L->head;
    pnode p;
    fscanf(fpR, "%s", ch);
    deCasePunc(ch);//lowercase and del punc
    while (!feof(fpR)) { //throughout file
        L->count++;
        if (isRem(ch) == false) {//remove common words
            p = locate(L, ch);
            if (p == NULL) {//ch not found in L
                addEnd(pTail, ch);
                pTail = pTail->next;
            } else { //ch found at p in L
                p->freq++;
            }
        }
        fscanf(fpR, "%s", ch);
        deCasePunc(ch);
    }
    p = L->head->next;
    while (p != NULL) {
        p->cent = (double) p->freq / (double) L->count * 100;
        p = p->next;
    }
}

void sort(linkedList *L) { //applying bubble sort
    int num = 0;
    int j;
    pnode p, q;
    q = L->head;
    while (q->next != NULL) {
        q = q->next;
        num++;
    }
    for (int i = 0; i < num - 1; i++) {
        p = L->head->next;
        q = L->head;
        j = num - i - 1;
        while (p->next != NULL && j != 0) {
            j--;
            if (p->freq < p->next->freq) {
                q->next = p->next;
                q = p->next;
                p->next = q->next;
                q->next = p;
                p = q;//cuz p was repointed
            }
            q = p;
            p = p->next;//q is the prevNode of p
        }
    }
}


void printList(linkedList L, FILE *fpW) {
    if (L.head->next == NULL) {
        printf("ERROR! INFO is empty!\n");
    } else {
        int i = 1;
        fprintf(fpW, "#    word                          frequency  percentage\n");
        pnode p = L.head->next;
        while (p != NULL) {
            fprintf(fpW, "%-5d%-30s%-11d%.2f%%\n", i, p->word, p->freq, p->cent);
            p = p->next;
            i++;
        }
    }
    fprintf(fpW, "\n %d words\n", L.count);
    printf("\"%s\" is the most used word in this article, %d times.\n", L.head->next->word, L.head->next->freq);
}

void linkFree(linkedList *L) {
    pnode tmp;
    pnode head = L->head;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}
