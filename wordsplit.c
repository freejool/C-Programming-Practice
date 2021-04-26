//
// Created by Sxing on 03/07/2021.
//

#include "wordsplit.h"

/*
 * usage:
 *  gcc ./wordsplit.c
 *  ./a.out input_file_name output_file_name
 */
int main(int argc, char *argv[]) {
    setbuf(stdout, NULL);
    char inFilename[255];
    char outFilename[255];
    FILE *fpR;//read pointer
    FILE *fpW;//write pointer
    if (argc > 3) {
        printf("Too many parameters.\n");
        return -1;
    } else if (argc < 3) {
        printf("Too few parameters.\n");
        return -1;
    } else {
        strcpy(inFilename, argv[1]);
        strcpy(outFilename, argv[2]);
    }
    if ((fpR = fopen(inFilename, "r")) == NULL) {
        printf("ERROR! Failed to read!");
        return -1;
    }
    if ((fpW = fopen(outFilename, "w+")) == NULL) {
        printf("ERROR! Failed to write!");
        return -1;
    }

    linkedList info;
    initLlist(&info, fpR);//initialize INFO
    sort(&info);//sort and count
    printList(info, fpW);//output data into assigned file

    linkFree(&info);//Free memory
    fclose(fpR);
    fclose(fpW);
    printf("Done!\n");
    return 0;
}
