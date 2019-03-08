#include <stdio.h>
#include <stdlib.h>

// Prototypes of the functions.
int ver_sum_1(int [], int, int); 
int ver_sum_2(int [], int, int);

int main(int argc, char *argv[]) {
	// Our array with integer elements. 
	int A[4] = {10, 15, 3, 7};
	
	// Our k-numbers. 
	int k1 = 17; 
	int k2 = 11; 
	int k3 = 13; 

	// With two printf we print two function's results.
	printf("Version 1 @ %d\n", ver_sum_1(A, 4, k1));
	printf("Version 2 @ %d\n", ver_sum_2(A, 4, k3));
}

int ver_sum_1(int A[], int size, int k) {
	int result = 0; 

	// The first loop run from the first element of the array to the last element
	// of the same array. 
	for(int i = 0; i < size; i++) {
		if(k-A[i] > 0) {
			// Also the second loop run from the first element to the last of the array, 
			// because we need to check if there is an element that is the complement of
			// the k-element. 
			for(int j = 0; j < size; j++) {
				if((k-A[i]) == A[j]) {
					result = 1;
					break; 	
				}
			}
		}
	}

	return result; 
}

int ver_sum_2(int A[], int size, int k) {
	// It works only if the array is sorted. 
	int result = 0; 
	int i = 0; 
	int j = size; 

	// The loop run until the two index do not intersect, but if they do then 
	// we get out from the loop. 
	while(i < j) {
		if(A[i]+A[j] == k) {
			result = 1; 
		       	break; 	
		} else if(A[i]+A[j] > k) {
			// If the sum is greater of k-element, then 
			// j = j - 1, because we move backwards. 
			j -= 1; 
		} else {
			// If the sum is smaller of k-element, then
			// i = i + 1, because we move forward. 
			i += 1; 
		}
	}

	return result; 
}
