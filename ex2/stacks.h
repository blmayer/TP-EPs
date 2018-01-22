/*
 *  Here we have auxiliary functions intended to be used by the main program.
 */

#ifndef STACKS_H_INCLUDED
#define STACKS_H_INCLUDED

#include <stdio.h>

#define MAXSTACK 20

/* Define our Duracell type */
struct stack {
    int top;
    int item[MAXSTACK];
};
typedef struct stack stack;

/* Initialize our stack */
void initialize(stack *p) {
    p -> top = -1;
}

/* Returns the stack position */
int top(stack *p) {
    return p -> top;
}

/* Remove all elements from to stack */
int empty(stack *p) {
    while(top(p) > -1) {
        p -> item[top(p)] = -1;   // -1 so we don't use negative values
        p -> top = top(p) - 1;    // top goes down
    }

    return 0;
}

/* Check if the stack is empty */
int isempty(stack *p) {
    if(top(p) == -1) {
        return 1;
   } else {
        return -1;
   }
}

/* Check if the stack is full */
int isfull(stack *p) {
    if(top(p) + 1 == MAXSTACK) {
        return 1;
    } else {
        return -1;
    }
}

/* Put a new element in the stack */
int put(int d, stack *p) {
    if(!isfull(p)) {
        p -> top = top(p) + 1;
        p -> item[top(p)] = d;
        return d;
    }
    return -1;
}

/* Get the last element from the stack */
int pop(stack *p) {
    if(!isempty(p)) {
        int element = p -> item[top(p)];
        p -> item[top(p)] = -1;
        p -> top = top(p) - 1;
        return element;
    }
    return -1;
}

/* Print the stack's elements */
void printstack(stack *p) {
    /* Create a temporary stack */
    stack *temp;
    initialize(temp);

    /* Pop, print and put back elements on stack */
    while(!isempty(p)) {
        int el = pop(p);
        printf("%d\n", el);
        put(el, temp);
    }

    while(!isempty(temp)) {
        put(pop(temp), p);
    }
}

/* Remove one specific element from the stack */
int drop(int d, stack *p) {
    /* Create a new temporary stack */
    stack *temp;
    initialize(temp);

    /* Look for the element wanted */
    while(put(pop(p), temp) != d && top(p) > 0) {
        /* Just keep going */
    }

    /* The element was found, remove it */
    if(top(p) > -1) {
        pop(temp);
    }

    /* Now put back the itens */
    while(put(pop(temp), p) > -1) {
        /* Just keep going */
    }
    
    return 0;
}

#endif

