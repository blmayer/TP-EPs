/*
 * ****************************************************************************
 *
 * PROJECT:     Topicos de Programação
 *
 * TITLE:       Dijkstra exercise
 *
 * DESCRIPTION: Here I define a directed graph structure and develop the 
 *              Dijkstra's algorithm to find all minimum paths between vertex A
 *              and all others.
 *
 * AUTHOR:      Brian Mayer blmayer@icloud.com
 *
 * NOTES:       Very hard for me!
 *
 * COPYRIGHT:   All rigths reserved. All wrongs deserved. (Peter D. Hipson)
 *
 * ****************************************************************************
 */

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

#define MAXNODES 10
#define MAXLINKS 20

typedef struct link {
    char *src;
    char *dest;
    int weight;
} link;

typedef struct node {
    char *name;
    link pairs[MAXLINKS];
} node;

typedef struct graph {
    int n;
    int e;
    link edges[MAXLINKS];
    node nodes[MAXNODES];
} graph;

int main(void) {

    /* Create our graph */
    graph G;
    G.n = 5;
    G.e = 9;

    /* Create the nodes */
    node A = {"a", {{"a", "c", 8}, {"a", "e", 2}}};
    node B = {"b", {{"b", "a", 3}, {"b", "d", 1}, {"b", "e", 7}}};
    node C = {"c", {{"c", "b", 4}}};
    node D = {"d", {{"d", "a", 2}, {"d", "c", 5}}};
    node E = {"e", {{"e", "d", 6}}};

    G.nodes[0] = A;
    G.nodes[1] = B;
    G.nodes[2] = C;
    G.nodes[3] = D;
    G.nodes[4] = E;
   
    /* Print thier names to check */
    puts("G stands as follows:");

    int i = 0, j = 0;
    while(i < G.n){
        printf("G has the node named %s\n", G.nodes[i].name);
        j = 0;
        printf("\tWhich has links to:");
        while(G.nodes[i].pairs[j].dest != NULL){
            printf(" %s", G.nodes[i].pairs[j].dest);
            j++;
        }
        puts("");
        i++;
    }

    /* Print distances from a vertex */
    int path_cost(node src, node dest){
        int k = 0;
        w = src.pairs[k].weight;
        k++;

        while(src.pairs[k].dest != NULL){
            if(src.pairs[k].weight < w){
                w = src.pairs[k].weight;
            }


        return 0;
    }


    return 0;
}

