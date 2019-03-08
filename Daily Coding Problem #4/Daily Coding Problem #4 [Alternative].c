#include <stdio.h>
#include <stdlib.h>

int max_sum_alternative(int [], int);

int main(int argc, char *argv[]) {
    // We declare an array of ints, and define the size of this.
    int arrayA[] = {2, 4, 6, 2, 5};
    int sizeA    = 5;
    
    int arrayB[] = {5, 1, 1, 5};
    int sizeB    = 4;
    
    int arrayC[] = {5, 1, 10, 5, 10, 1, 11, 2};
    int sizeC    = 8;
    
    printf("Sum @ %d\n", max_sum_alternative(arrayB, sizeB));
}

int max_sum_alternative(int array[], int size) {
    int current_sum = 0;
    int max_sum     = 0;
    int zndex       = 0;
    
    // The first loop starts from the first element of the array
    // until the third element of the array.
    for(int index = 0; index <= 2 && index < size; index++) {
        
        // The second loop starts from index+2 because
        // we don't want the adjacent elements of the
        // current element.
        for(int jndex = index+2; jndex <= index+3 && jndex < size; jndex++) {
            
            // The current sum is the sum of the current (index)
            // element with the element punted by the second index
            // (jndex) of the second loop.
            current_sum = array[index] + array[jndex];

            // The zndex punted the first element that isn't adjacent
            // of the jndex-element. So the while loop starts only if
            // this index (zndex) is lower than size of array.
            // With this method the while loop sum only non-adjacent
            // elements of the array.
            zndex = jndex+2;
            while(zndex < size) {
                current_sum += array[zndex];
                zndex += 2;
            }
            
            
            // If the current sum is greater than the previous
            // max sum, the max sum assumes the value of the
            // current sum.
            if(current_sum > max_sum) {
                max_sum = current_sum;
            }
            
            // Of course, we reset the current sum for the next iteration. 
            current_sum = 0;
        }
    }
    
    return max_sum;
}
