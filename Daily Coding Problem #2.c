#include <stdio.h>
#include <stdlib.h>

void first_function(int [], int); 
void second_function(int [], int); 

int main(int argc, char *argv[]) {
    int arrayA[5] = {1, 2, 3, 4, 5};
    
    first_function(arrayA, 5);
    second_function(arrayA, 5); 
}

void first_function(int arrayA[], int size) {
    int result = 1; 

    // We have two nested loops, both starts from the first to the last 
    // element of the array. We have to check if the index of the first 
    // loop is equal to the index of the second loop. 
    for(int index = 0; index < size; index++) {
        for(int jndex = 0; jndex < size; jndex++) {
            // With this control, we exclude the current element of the iteration.
            if(index != jndex) {
                result *= arrayA[jndex]; 
            }
        }

        printf("%d\t", result);
        result = 1; 
    }   
    
    printf("\n");
}

void second_function(int arrayA[], int size) {
    // First of all, we calculate the multiplication of all the elements of the array. 
    int multiplication = 1; 
    for(int index = 0; index < size; index++) {
        multiplication *= arrayA[index]; 
    }

    // After that, after the multiplication has to divide by the current element. 
    for(int jndex = 0; jndex < size; jndex++) {
        printf("%d\t", (multiplication/arrayA[jndex]));
    }

    printf("\n");
}
