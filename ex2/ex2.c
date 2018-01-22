#include "stacks.h"

int main(void) {
    stack *duracell;
    initialize(duracell);
    puts("1");
    printf("Is empty: %d\n", isempty(duracell));
    put(5, duracell);
    printf("Is empty: %d\n", isempty(duracell));
    put(3, duracell);
    put(9, duracell);
    put(13, duracell);
    put(7, duracell);
    put(1, duracell);
    printstack(duracell);
    drop(10, duracell);
    printstack(duracell);

    return 0;
}

