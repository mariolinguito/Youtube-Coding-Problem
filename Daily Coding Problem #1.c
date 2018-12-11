#include <stdio.h>
#include <stdlib.h>

int ver_sum_1(int [], int, int); 
int ver_sum_2(int [], int, int);

int main(int argc, char *argv[]) {
	int A[4] = {10, 15, 3, 7};
	int k1 = 17; 
	int k2 = 11; 
	int k3 = 13; 

	printf("Version 1 @ %d\n", ver_sum_1(A, 4, k1));
	printf("Version 2 @ %d\n", ver_sum_2(A, 4, k3));
}

int ver_sum_1(int A[], int size, int k) {
	int result = 0; 

	for(int i = 0; i < size; i++) {
		if(k-A[i] > 0) {
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

	while(i < j) {
		if(A[i]+A[j] == k) {
			result = 1; 
		       	break; 	
		} else if(A[i]+A[j] > k) {
			j -= 1; 
		} else {
			i += 1; 
		}
	}

	return result; 
}
