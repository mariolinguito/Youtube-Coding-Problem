#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

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
    NODE nodes[SIZE];
    
    nodes[0].start = 30;
    nodes[0].end   = 75;
    
    nodes[1].start = 0;
    nodes[1].end   = 50;
    
    nodes[2].start = 60;
    nodes[2].end   = 150;
    
    /*
    nodes[3].start = 3;
    nodes[3].end   = 10;
    
    nodes[4].start = 15;
    nodes[4].end   = 20;
    
    nodes[5].start = 16;
    nodes[5].end   = 35;
     */
    
    printf("Array:\n");
    for(int index = 0; index < SIZE; index++) {
        printf("(%d %d)\t", nodes[index].start, nodes[index].end);
    }   printf("\n");
    
    // We can call the two functions to estimate
    // the minimum rooms based on nodes start and end time.
    printf("Rooms (with fst. function) @ %d\n", how_many_rooms_1(nodes, SIZE));
    printf("Rooms (with scd. function) @ %d\n", how_many_rooms_2(nodes, SIZE));
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
    int rooms  = 0;
    int max_r  = 0;
    
    // The loop starts from the first element of the array
    // until the last element of the same array of struct.
    for(int index = 0; index < size; index++) {
        rooms = 1;
        
        for(int jndex = 0; jndex < size; jndex++) {
            
            // We check if the current index element falls into the range of jndex intervals.
            // If so, we increment the number of rooms.
            if(nodes[index].start > nodes[jndex].start && nodes[index].start < nodes[jndex].end) {
                rooms += 1;
            }
        }
        
        // After the second loops, we check if the number of rooms is greater than
        // max_r, if so, we insert rooms into max_r variable.
        if(rooms > max_r) {
            max_r = rooms;
        }
    }
    
    return max_r;
}
