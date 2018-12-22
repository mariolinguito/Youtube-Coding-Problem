#include <stdio.h>
#include <stdlib.h>

// The struct has two fields of integer, the first
// is the start time and the second is the end time.
struct node {
    int start;
    int end;
};

typedef struct node NODE;

int how_many_rooms_1(NODE [], int);
int how_many_rooms_2(NODE [], int);
void swap(NODE *xp, NODE *yp);
void selection_sort(NODE [], int);

int main(int argc, char *argv[]) {
    
    // We create an array of struct node!
    NODE nodes[7];
    
    nodes[0].start = 70;
    nodes[0].end = 85;
    
    nodes[1].start = 0;
    nodes[1].end = 50;
    
    nodes[2].start = 30;
    nodes[2].end = 75;
    
    nodes[3].start = 20;
    nodes[3].end = 45;
    
    nodes[4].start = 60;
    nodes[4].end = 150;
    
    nodes[5].start = 5;
    nodes[5].end = 25;
    
    nodes[6].start = 10;
    nodes[6].end = 100;
    
    // We need an ordered array, so we need selection sort
    // algorithm to order the nodes.
    selection_sort(nodes, 7);

    // Once it is ordered, we can call the two functions to estimate
    // the minimum rooms based on nodes start and end time.
    printf("Rooms (with fst. function) @ %d\n", how_many_rooms_1(nodes, 7));
    printf("Rooms (with scd. function) @ %d\n", how_many_rooms_2(nodes, 7));
}

int how_many_rooms_1(NODE nodes[], int size) {
    int rooms = 1;
    
    // The loop starts from the first element of the array
    // until the penultimate element of the same array of struct.
    for(int index = 0; index < size-1; index++) {
        
        // We confront the start time of the second element
        // and the end of the first element if the first is
        // lower than second, so we increment the rooms.
        if(nodes[index+1].start < nodes[index].end) {
            rooms += 1;
        }
    }
    
    return rooms;
}

int how_many_rooms_2(NODE nodes[], int size) {
    int rooms = 1;
    
    // The loop starts from the first element of the array
    // until the penultimate element of the same array of struct.
    for(int index = 0; index < size-1; index++) {
        
        // With the control we check the range: NODES+1.START < NODES.END < NODES+1.END..
        // If the current node falls into the range of next node, so we increment the rooms.
        if(nodes[index].end > nodes[index+1].start && nodes[index].end < nodes[index+1].end) {
            rooms += 1;
        }
    }
    
    return rooms;
}

// ****************************************************************
// **  These are the implementation of swap function and of the  **
// **  selection sort algorithm.                                 **
// ****************************************************************
void swap(NODE *xp, NODE *yp) {
    NODE temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selection_sort(NODE nodes[], int size) {
    int i, j, min_idx;
    
    for (i = 0; i < size-1; i++) {
        min_idx = i;
        
        for (j = i+1; j < size; j++) {
            if (nodes[j].start < nodes[min_idx].start) {
                min_idx = j;
            }
        }
        
        swap(&nodes[min_idx], &nodes[i]);
    }
}
