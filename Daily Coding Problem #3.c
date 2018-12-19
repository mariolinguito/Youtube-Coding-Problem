#include <stdio.h>
#include <stdlib.h>

// The struct has two fields of integer, the first
// is the start time and the second is the end time.
struct node {
    int start;
    int end;
};

typedef struct node NODE;

int how_many_rooms(NODE [], int size);

int main(int argc, char *argv[]) {
    
    // We create an array of struct node!
    NODE nodes[4];
    nodes[0].start = 30;
    nodes[0].end = 75;
    
    nodes[1].start = 0;
    nodes[1].end = 50;
    
    nodes[2].start = 60;
    nodes[2].end = 150;
    
    nodes[3].start = 3;
    nodes[3].end = 170;
    
    nodes[4].start = 165;
    nodes[4].end = 180;
    
    printf("Rooms @ %d\n", how_many_rooms(nodes, 4));
}

int how_many_rooms(NODE nodes[], int size) {
    int rooms = 1;
    
    // The loop starts from the first element of the array
    // until the last element of the same array of struct.
    for(int index = 0; index < size; index++) {
        
        // We confront the start time of the second element
        // and the end of the first element if the first is
        // lower than second, so we increment the rooms.
        if(nodes[index+1].start < nodes[index].end) {
            rooms += 1;
        }
    }
    
    return rooms;
}

