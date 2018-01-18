#include <stdio.h>
#include <stdlib.h>

// Define our doublely linked list
struct dllist {
    int val;
    struct dllist *prev;
    struct dllist *next;
};

// To not need to type struct
typedef struct dllist dllist;

// Function to add an element to a dllist
void insert(int new, dllist *lst) {

    // Create the new element
    dllist *cur;
    dllist *temp = malloc(sizeof(dllist));
    temp -> val = new;
    cur = lst;

    // Loop in our list to find the correct place to insert the new element
    while(cur -> val < new) {
        cur = cur -> next;
    }
    printf("current val is %d\n", cur -> val);
    
    temp -> val = cur -> val;
    cur -> val = new;

    temp -> next = cur;
    temp -> prev = cur -> prev;
}

void drop(int del, dllist *lst) {

    // Create the new element
    dllist *el;
    dllist *temp = malloc(sizeof(dllist));
    el = lst;

    // Loop in our list to find the correct place to insert the new element
    while(el -> next != NULL && el -> val != del) {
        el = el -> next;
    }
    printf("el val is %d\n", el -> val);
}

void print_list(dllist *lst) {

    dllist *cur = lst;
    printf("%d\n", cur -> val);

    if(cur -> next != NULL) {
        print_list(cur -> next);
    }
}

void main(void) {

    dllist *ages = malloc(sizeof(dllist));
    ages -> val = 2;
    ages -> prev = NULL;
    ages -> next = NULL;

    // Insert new elements
    insert(4, ages);
    // insert(10, ages);
    // insert(3, ages);
    // insert(7, ages);
    // insert(12, ages);
    // insert(4, ages);

    puts("Inserted.");

    // Printing values
    print_list(ages);
}

