/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. 
Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/
#include <stdio.h>
struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int check_year(char *dob1, char *dob2){
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
int check_month(char *dob1, char *dob2){
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
int check_date(char *dob1, char *dob2){
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
int older_date(char *dob1, char *dob2){
	//Function to compare years
	int year = check_year(dob1, dob2);
	printf("year %d\n", year);
	if (year == 1)//year1 > year2
		return 1;
	else if (year == 2)//year1 < year2
		return 2;
	else if (year == 0)
		return 0;
	else{
		//Function to compare months
		int mon = check_month(dob1, dob2);
		if (mon == 1)// mon1 > mon2
			return 1;
		else if (mon == 2)// mon1 < mon2
			return 2;
		else if(mon == 0)
			return 0;
		else{
			//Function to compare dates
			int date = check_date(dob1, dob2);
			if (date == 1)// date1 > date2
				return 1;
			else if (date == 2)// date1 < date2
				return 2;
			else
				return 0;
		}
	}
}
int compare_dates(char *date, char *date2){
		return older_date(date, date2);
	/*int index = 0;
	while (index < 10){
		if (date[index] == date2[index]){
			index++;
		}
		else return 0;
	}
	return 1;*/
}
int bin_search(struct transaction *Arr, int len, char *date){
	int first = 0;
	int last = len - 1;
	int mid;
	int temp_var = 0;
	while (first <= last){
		mid = (first + last) / 2;
		printf("mid is %d\n", mid);
		temp_var = compare_dates(date, Arr[mid].date);
		if (temp_var == 0){
			if (compare_dates(date, Arr[mid - 1].date) == 0)
				return -1;
			else
				return mid;
		}
		else if (temp_var == 1)
			first = mid + 1;
		else
			last = mid - 1;
	}
	return -1;
	/*int index = -1;
	int count = 0;
	for (int i = 0; i < len; i++){
		if (compare_dates(date, Arr[i].date)){
			index = i;
			count++;
			if (count > 1)
				return -1;
		}
			
	}
		return index;*/
}
int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	int index = bin_search(Arr, len, date);
	printf("index %d\n", index);
	if (index >= 0)
		return len - index - 1;
	return 0;
}
