/*
Well Done for completing the first part of the C Course ,If you didnt finish 
Do complete them and come here again . 

Use MainArrays2 File for testing any other function in other Cpp files of the Strings Project.

DO NOT write main function in any other File or else your Build Fails.s

Objectives of C-Arrays-2 Lesson:

->Handling Arrays of Structures
->Sorting Arrays
->Learning Complexities of your Algorithm

*/
#include <stdio.h>
#include "FunctionHeadersArrays2.h"
struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int main(){

	//Test countGreaterNumbers
	//struct transaction Arr[5] = { { 60, "09-10-2003", "First" }, { 70, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" }, { 90, "21-05-2006", "Fourth" }, { 10, "29-11-2007", "Fifth" } };
	//int count = countGreaterNumbers(Arr, 5, "09-10-2003");
	//printf("count %d\n", count);
	//Test findSingleOccurenceNumber
	int A[10] = { 12, 1, 12, 3, 12, 1, 1, 2, 3, 3 };
	int res = findSingleOccurenceNumber(A, 10);
	printf("res %d\n", res);

	//Test mergeSortedArray
	/*struct transaction A[3] = { { 40, "09-10-2003", "Fourth" }, { 60, "19-10-2004", "Sixth" }, { 80, "03-03-2005", "Eigth" } };
	struct transaction B[3] = { { 40, "09-10-2003", "Fourth" }, { 50, "19-10-2003", "Fifth" }, { 60, "19-10-2004", "Sixth" } };
	//int A[3] = { 1, 2, 3 }, B[3] = { 1, 2, 3 };
	struct transaction *result = mergeSortedArrays(A, 3, B, 3);
	for (int i = 0; i < 6; i++)
		printf("%d %s %s\n", result[i].amount, result[i].date, result[i].description);*/
	//Test sortedArraysCommonElements
	/*struct transaction A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
	struct transaction B[3] = { { 40, "21-10-2006", "Fourth" }, { 50, "13-11-2007", "Fifth" }, { 60, "13-08-2008", "Sixth" } };
	struct transaction *result = sortedArraysCommonElements(A, 3, B, 3);*/
	//for (int i = 0; i < 6; i++)
		//printf("%d %s %s\n", result[i].amount, result[i].date, result[i].description); 

	return 0;
}