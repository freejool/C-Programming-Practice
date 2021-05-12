#include "head.h"

int main(int args, char *argv[]) {
    setbuf(stdout, NULL);

    if (inputs(argv[1]) == False) {
        return -1;
    }
    init_cluster();
    KMeans();
    verify(argv[1],argv[2]);

    return 0;
}
