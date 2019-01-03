#include <stdio.h>
#include <stdlib.h>

void median_array(int [], int);
int insertion_sort(int *, int);

int main(int argc, char *argv[]) {
    int   array[] = {2, 1, 5, 7, 2, 0, 5};
    int   size    = 7;
    float median_a[size];
    
    median_array(array, size);
}

// The input parameters are the array of integers
// and the size of the array itself.
void median_array(int array[], int size) {
    // The first index flow on the array, the second
    // index (jndex) is used for show the result array.
    // In the end, the median is used for getting the
    // median element of the odd array.
    int   index  = 0;
    int   jndex  = 0;
    int   median = 0;
    
    // The first float is used for the sum of two median
    // integers of the ordered portion of the array. The
    // second is the result array.
    float sum    = 0;
    float median_array[size];
    
    for(index = 0; index < size; index++) {
        // Before the operations, we need to order the portion
        // of the array delimited by the index. For this purpose,
        // we need to use an algorithm for the ordination of the
        // elements, and because of the number of elements is small,
        // it is convenient the use of the Insertion Sort because
        // in the favourite case it is efficient.
        insertion_sort(array, index+1);
        
        // We need to check if the module of the index is not equal
        // to zero. If yes, we need to check if the index is higher
        // than zero, because if it is equal to zero, the portion of
        // the array consists in only one element. If index > zero,
        // we need to sum the two middle elements of the array, because
        // the number of elements of the array is even. After that,
        // we divite the sum by two, and then we insert the result in
        // the result array.
        //
        // Else the number of the elements of the portion of the array
        // is not even, so we need the median of the array. Then we
        // insert it into the array.
        if((index%2) != 0) {
            if(index > 0) {
                sum = (array[(index+1)/2] + array[((index+1)/2)-1]);
                median_array[index] = sum/2;
            } else {
                median_array[index] = array[index];
            }
        } else {
            median = index/2;
            median_array[index] = array[median];
        }
    }
    
    for(index = 0; index < size; index++) {
        printf("%f\n", median_array[index]);
    }
}

// Implementation of the insertion sort algorithm. See the video
// for the complete explanation.
int insertion_sort(int *array, int size) {
    int index = 0;
    int jndex = 0;
    int key   = 0;
    
    for(index = 1; index < size; index++) {
        key = array[index];
        jndex = index-1;
        
        while(jndex >= 0 && array[jndex] > key) {
            array[jndex+1] = array[jndex];
            jndex = jndex-1;
        }
        
        array[jndex+1] = key;
    }
    
    return *array;
}
