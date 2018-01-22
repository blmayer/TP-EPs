/*
 *  Here we have auxiliary functions intended to be used by the main program.
 */

#ifndef QUEUES_H_INCLUDED
#define QUEUES_H_INCLUDED

#include <stdio.h>

#define MAXQUEUE 20

/* Define our Duracell type */
struct queue {
    int start, end;
    int itens[MAXQUEUE];
};
typedef struct queue queue;

/* Initialize our queue */
void initialize(queue *p) {
    p -> start = itens[0];
    p -> end = itens[0];
}

/* Returns the queue start */
int start(queue *p) {
    return p -> start;
}

/* Returns the queue end */
int end(queue *p) {
    return p -> end;
}

/* Remove all elements from to queue */
int empty(queue *p) {
    while(start(p) != end(p)) {
        p -> itens[end(p)] = -1;   // -1 so we don't use negative values
        p -> end = end(p) - 1;     // end goes down
    }

    return 0;
}

/* Check if the queue is empty */
int isempty(queue *p) {
    if(start(p) == end(p) {
        return 1;
   } else {
        return -1;
   }
}

/* Check if the queue is full */
int isfull(queue *p) {
    if(end(p) + 1 == MAXQUEUE) {
        return 1;
    } else {
        return -1;
    }
}

/* Put a new element in the queue */
int put(int d, queue *p) {
    if(!isfull(p)) {
        p -> end = end(p) + 1;
        p -> itens[end(p)] = d;
        return d;
    }
    return -1;
}

/* Get the last element from the queue */
int pop(queue *p) {
    if(!isempty(p)) {
        int element = p -> itens[end(p)];
        p -> itens[end(p)] = -1;
        p -> end = end(p) - 1;
        return element;
    }
    return -1;
}

/* Print the queue's elements */
void printqueue(queue *p) {
    /* Create a temporary queue */
    queue *temp;
    initialize(temp);

    /* Pop, print and put back elements on queue */
    while(!isempty(p)) {
        int el = pop(p);
        printf("%d\n", el);
        put(el, temp);
    }

    while(!isempty(temp)) {
        put(pop(temp), p);
    }
}

/* Remove one specific element from the queue */
int drop(int d, queue *p) {
    /* Create a new temporary queue */
    queue *temp;
    initialize(temp);

    /* Look for the element wanted */
    while(put(pop(p), temp) != d && end(p) > 0) {
        /* Just keep going */
    }

    /* The element was found, remove it */
    if(end(p) > -1) {
        pop(temp);
    }

    /* Now put back the itens */
    while(put(pop(temp), p) > -1) {
        /* Just keep going */
    }
    
    return 0;
}

#endif

