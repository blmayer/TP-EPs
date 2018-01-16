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
    dllist *el = malloc(sizeof(dllist));
    el = lst;

    // Loop in our list to find the correct place to insert the new element
    while(el -> next != NULL && el -> val < new) {
        printf("val is %d\n", el -> val);
        el = el -> next;
    }

    puts("Out of loop");
    if(el -> next == NULL) {
        el -> next -> val = new;
        el -> next -> next = NULL;
        el -> next -> prev = el;
    } else {
        el -> prev -> next = el;
        el -> next -> prev = el;

    }

}

void main(void) {
    dllist *ages = malloc(sizeof(dllist));
    dllist *ages1 = malloc(sizeof(dllist));
    dllist *ages2 = malloc(sizeof(dllist));
    dllist *ages3 = malloc(sizeof(dllist));

    ages -> next = ages1;
    ages1 -> next = ages2;
    ages2 -> next = ages3;
    ages3 -> next = NULL;

    ages -> prev = NULL;
    ages1 -> prev = ages;
    ages2 -> prev = ages1;
    ages3 -> prev = ages2;

    ages -> val = 2;
    ages1 -> val = 3;
    ages2 -> val = 8;
    ages3 -> val = 10;

    printf("%d\n", ages -> val);
    printf("%d\n", ages -> next -> val);

    // Insert new element
    // insert(28, ages);
    dllist *el = malloc(sizeof(dllist));
    el = ages;

    puts("Inserted.");

    printf("%d\n", el -> val);
    printf("%d\n", el -> next -> next -> next -> next);

    // Printing values
}

