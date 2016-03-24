/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
There are better ways of solving the problem than a brute-force solution which is of O(n^2)
complexity .
*/
#include <stdio.h>
/*void swap(int *num1, int *num2){
	*num1 = *num1 + *num2;
	*num2 = *num1 - *num2;
	*num1 = *num1 - *num2;
}*/
int partition(int A[], int start, int end){
	int pivot = A[end];
	int p_index = start;
	for (int i = start; i <= end - 1; i++){
		if (A[i] <= pivot){
			//swap(&A[i], &A[p_index]);
			A[i] = A[i] + A[p_index];
			A[p_index] = A[i] - A[p_index];
			A[i] = A[i] - A[p_index];
			p_index++;
		}
	}
	//swap(&A[end], &A[p_index]);
	A[p_index] = A[p_index] + A[end];
	A[end] = A[p_index] - A[end];
	A[p_index] = A[p_index] - A[end];
	return p_index;
}
void quick_sort(int A[], int start, int end){
	if (start < end){
		int pindex = partition(A, start, end);
		quick_sort(A, start, pindex - 1);
		quick_sort(A, pindex + 1, end);
	}
}
int findSingleOccurenceNumber(int *A, int len) {
	if (A == NULL)
		return -1;
	for (int i = 0; i < len; i++){
		printf("%d\n", A[i]);
	}
	quick_sort(A, 0, len - 1);
	for (int i = 0; i < len; i++){
		printf("%d\n", A[i]);
	}
	for (int i = 0; i < len; i++){
		if (A[i] == A[i + 1])
			i = i + 3;
		else
			return A[i];
	}
}