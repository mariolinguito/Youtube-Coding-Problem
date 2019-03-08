#include <stdio.h>
#include <stdlib.h>

int search(int [], int);

int main(int argc, char *argv[]) {
    int A[10] = {6, 1, 1, 1, 3, 3, 3, 6, 7, 6};
    int size = 10;
    
    printf("Search @ %d\n", search(A, size));
}

int search(int A[], int size) {
    int first  = 0;
    int second = 0;
    int index  = 0;
    
    for(index = 0; index < size; index++) {
        second = second | (first & A[index]);
        first  = first ^ A[index];
        
        int fix = ~(first & second);
        first   = first & fix;
        second  = second & fix;
    }
    
    return first;
}
