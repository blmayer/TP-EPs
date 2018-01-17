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
    dllist *el;
    dllist *temp = malloc(sizeof(dllist));
    el = lst;
    temp -> val = new;

    // Loop in our list to find the correct place to insert the new element
    while(el -> next != NULL && el -> val < new) {
        printf("val is %d\n", el -> val);
        el = el -> next;
    }
    printf("el val is %d\n", el -> val);

    if(el -> val < new) {
        puts("after last");
        el -> next = temp;
        temp -> prev = el;
        temp -> next = NULL;
    } else {
        puts("before last");
        temp -> prev = el;
        temp -> next = el -> next;
        temp -> val = el -> val;
        el -> next = temp;
        el -> val = new;
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

    // Insert new element
    insert(11, ages);

    puts("Inserted.");

    // Printing values
    printf("first %d\n", ages -> val);
    printf("second %d\n", ages -> next -> val);
    printf("third %d\n", ages -> next -> next -> val);
    printf("fourth %d\n", ages -> next -> next -> next -> val);
    printf("fifth %d\n", ages -> next -> next -> next -> next -> val);

}

