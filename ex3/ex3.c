#include "queues.h"

int main(void) {
    stack *inss;
    initialize(inss);
    puts("1");
    printf("Is empty: %d\n", isempty(inss));
    put(5, inss);
    printf("Is empty: %d\n", isempty(inss));
    put(3, inss);
    put(9, inss);
    put(13, inss);
    put(7, inss);
    put(1, inss);
    printstack(inss);
    drop(10, inss);
    printstack(inss);

    return 0;
}

