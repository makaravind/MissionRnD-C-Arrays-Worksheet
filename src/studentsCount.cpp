
/*
OVERVIEW:  Write a function that takes ascending sorted student's score array and tells how many number of students got more marks and how many students got less marks than the given student.
E.g.: Input array: [10, 20, 30, 40, 50], score: 30, lessCount value is 2 (10, 20 are less than 30), moreCount value is 2 (40, 50 are greater than 30).

INPUTS: Ascending sorted student marks array, length of the array, one student score, lessCount and moreCount are to be
used to store final results.

OUTPUT: Update lessCount and moreCount with number of students less than and more than given score.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <stdio.h>
int BinarySearch(int*, int, int);
int IfSameElements(int*, int);
void * studentsCount(int *Arr, int len, int score, int *lessCount, int *moreCount) {

	if (Arr == NULL) return NULL;
	if (len == 1) {
		if (Arr[0] == score) {
			*lessCount = 0;
			*moreCount = 0;
			
		}
		else if (Arr[0] > score){
			*lessCount = 0;
			*moreCount = 1;
		}
		else if (Arr[0] < score){
			*lessCount = 1;
			*moreCount = 0;

		}
		
	}
	else if (len < 0) return NULL;
	else if (IfSameElements(Arr, len) == 1){
		*lessCount = 0;
		*moreCount = 0;
	}
	else{
		int index = BinarySearch(Arr, len, score);


		if (index != -1){
			*lessCount = index - 1;
			*moreCount = len - index;
		}
		else
			return NULL;
	}
	
}
int IfSameElements(int *ap, int size){
	int ref = ap[0];
	int flag = 0;
	for (int i = 1; i < size; i++) {
		if (ap[i] != ref) flag = 1;
	}
	if (flag == 1) return -1;
		return 1;
}
int BinarySearch(int *a, int n, int search){
	int first = 0;
	int last = n - 1;
	int middle = (first + last) / 2;

	while (first <= last) {
		if (a[middle] < search)
			first = middle + 1;
		else if (a[middle] == search) {
			return middle + 1;
			break;
		}
		else
			last = middle - 1;

		middle = (first + last) / 2;
	}
	if (first > last)
		return -1;
}

