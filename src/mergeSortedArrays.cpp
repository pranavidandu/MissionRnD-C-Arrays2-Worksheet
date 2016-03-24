/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int check_year_merge(char *dob1, char *dob2){
	int year1 = 0, year2 = 0;
	for (int i = 6; i <= 9; i++)
		year1 = year1 * 10 + dob1[i] - '0';
	for (int i = 6; i <= 9; i++)
		year2 = year2 * 10 + dob2[i] - '0';
	if (year1 < year2)
		return 2;
	else if (year1 > year2)
		return 1;
	else if (year1 == year2)
		return 0;
	return -1;

}
int check_month_merge(char *dob1, char *dob2){
	int mon1 = 0, mon2 = 0;
	for (int i = 3; i <= 4; i++)
		mon1 = mon1 * 10 + dob1[i] - '0';
	for (int i = 3; i <= 4; i++)
		mon2 = mon2 * 10 + dob2[i] - '0';
	if (mon1 < 0 || mon1 > 12 || mon2 < 0 || mon2 > 12)
		return -1;
	if (mon1 < mon2)
		return 1;
	else if (mon1 > mon2)
		return 2;
	else if (mon1 == mon2)
		return 0;
	return -1;
}
int check_date_merge(char *dob1, char *dob2){
	int date1 = 0, date2 = 0;
	for (int i = 0; i <= 1; i++)
		date1 = date1 * 10 + dob1[i] - '0';
	for (int i = 0; i <= 1; i++)
		date2 = date2 * 10 + dob2[i] - '0';

	if (date1 < date2)
		return 1;
	else if (date1 > date2)
		return 2;
	else if (date1 == date2)
		return 0;
	return -1;
}
int older_date_merge(char *dob1, char *dob2){
	//Function to compare years
	int year = check_year_merge(dob1, dob2);
	if (year == 1)//year1 > year2
		return 1;
	else if (year == 2)//year1 < year2
		return 2;
	else{
		//Function to compare months
		int mon = check_month_merge(dob1, dob2);
		if (mon == 1)// mon1 > mon2
			return 1;
		else if (mon == 2)// mon1 < mon2
			return 2;
		else{
			//Function to compare dates
			int date = check_date_merge(dob1, dob2);
			if (date == 1)// date1 > date2
				return 1;
			else if (date == 2)// date1 < date2
				return 2;
			else
				return 0;
		}
	}
}
struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if(A == NULL || B == NULL)
		return NULL;
	struct transaction *C = (struct transaction*)malloc(sizeof(struct transaction) * (ALen + BLen));
	int i = 0, j = 0, k = 0;
	int temp_var = 0;
	while (k < (ALen + BLen)){
		if (i > ALen - 1 || j > BLen - 1){//if all the dates of one of the bank statements are stored in C
			break;
		}
		temp_var = older_date_merge(A[i].date, B[j].date);//Function checks which date is older

		if (temp_var == 0){//if both the dates are same
			C[k++] = A[i++];
			C[k++] = B[j++];
		}
		else if (temp_var == 2){//if A[i].date is older
			if (i == (ALen - 1)){
				C[k++] = A[i];
				break;
			}
			else
				C[k++] = A[i++];
		}
		else {
			if (j == (BLen - 1)){
				C[k++] = B[j];
				break;
			}
			else
				C[k++] = B[j++];
		}
	}
	if (i <= ALen - 1 && i < j){
		while (i <= ALen - 1)
			C[k++] = A[i++];
	}
	else{
		while (j <= BLen - 1){
			C[k++] = B[j++];
		}
	}
	return C;
}