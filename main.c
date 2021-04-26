#include "head.h"

//
// Created by sxing on 2021/4/21.
//

int main(int argc, char *argv[]) {
    setbuf(stdout, NULL);
    read_data(argv[1], argv[2]);
    init_BP_network();
    train_network();
    test_network(argv[3]);

    return 0;
}
