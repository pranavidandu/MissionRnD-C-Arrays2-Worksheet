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
#include <malloc.h>
void merge(int *A, int min, int mid, int max)
{
	int *temp_array = (int*)malloc(sizeof(int)*max);
	int i, j, k, m;
	j = min;
	m = mid + 1;
	for (i = min; j <= mid && m <= max; i++)
	{
		if (A[j] <= A[m])
		{
			temp_array[i] = A[j];//left sub array
			j++;
		}
		else
		{
			temp_array[i] = A[m];//right sub array
			m++;
		}
	}
	if (j>mid)//if all the left sub array elements are merged
	{
		for (k = m; k <= max; k++)
		{
			temp_array[i] = A[k];
			i++;
		}
	}
	else
	{
		for (k = j; k <= mid; k++)
		{
			temp_array[i] = A[k];
			i++;
		}
	}
	for (k = min; k <= max; k++)
		A[k] = temp_array[k];
}
void partition_merge(int *A, int low, int high)
{
	int mid;
	if (low < high) {
		mid = (low + high) / 2;
		partition_merge(A, low, mid);
		partition_merge(A, mid + 1, high);
		merge(A, low, mid, high);
	}
	return;
}
int findSingleOccurenceNumber(int *A, int len) {
	if (A == NULL)
		return -1;
	partition_merge(A, 0, len - 1);
	for (int i = 0; i < len; i++){
		if (A[i] == A[i + 1])
			i = i + 2;
		else
			return A[i];
	}
}