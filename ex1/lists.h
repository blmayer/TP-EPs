/*
 *  Here we have auxiliary functions intended to be used by the main program.
 */

#ifndef LISTS_H_INCLUDED
#define LISTS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

/* Define our doublely linked list */
struct dllist {
    int val;
    struct dllist *prev;
    struct dllist *next;
};
typedef struct dllist dllist;

/* Initialize a list */
void initialize(dllist *lst) {
	
	lst = malloc(sizeof(dllist));
    lst -> val = 0;
	lst -> prev = NULL;
	lst -> next = NULL;
}

/* Printing list's values */
void printfrd(dllist *lst) {

    dllist *cur = lst;
    printf("%d\n", cur -> val);

    if(cur -> next != NULL) {
        printfrd(cur -> next);
    }

}

/* Printing list's values backwards */
void printbck(dllist *lst) {

    dllist *cur = lst;

	while(cur -> next != NULL) {
        cur = cur -> next;
	}
    
	while(cur -> prev != NULL) {
        printf("%d\n", cur -> val);
        cur = cur -> prev;
	}
	
	printf("%d\n", cur -> val);
}

/* 
 * Adding and removing elements from lists
 */

/* Add an element while preserving the sort order */
void insert(dllist *lst, int new) {

    /* Create the new element */
    dllist *temp = malloc(sizeof(dllist));
    temp -> val = new;
	
	/* Create a cursor to point to our list's elements */
	dllist *cur;
	cur = lst;

    /* Find the correct place to insert the new element */
    while(cur -> val < new) {
        cur = cur -> next;
    }
    printf("current val is %d\n", cur -> val);
    
	/* Update pointers */
    temp -> val = cur -> val;
    cur -> val = new;

    temp -> next = cur;
    temp -> prev = cur -> prev;
}

/* Add an element to the beginning of a dllist */
void push(dllist *lst, int new) {

    /* Create the new element */
    dllist *temp = malloc(sizeof(dllist));
    temp -> val = new;

	/* Update pointers */
	temp -> next = lst;
	temp -> prev = NULL;
	lst = temp;
}

/* Add an element to the end of a dllist */
void append(dllist *lst, int new) {

    /* Create the new element */
    dllist *temp = malloc(sizeof(dllist));
    temp -> val = new;
	
	/* Create a cursor to point to our list's elements */
	dllist *cur;
	cur = lst;
	
    /* Loop in our list to the end */
    while(cur -> next != NULL) {
        cur = cur -> next;
    }
	
	/* Update pointers */
	cur -> next = temp;
	temp -> prev = cur;
	temp -> next = NULL;
}

void drop(dllist *lst, int del) {

	/* Create a cursor to point to our list's elements */
	dllist *cur;
	cur = lst;

    /* Find the element to be removed */
    while(cur -> next != NULL && cur -> val != del) {
        cur = cur -> next;
    }

	/* Check if element was found */
	if(cur -> val == del) {
        	
        /* Update pointers */
        if(cur -> prev == NULL) {
            /* Removing first element */
            lst = lst -> next;
            lst -> prev = NULL;
        }
        
        /* Free the memory */
        free(cur);
         
	} else {
        puts("error");
	}
}

#endif

