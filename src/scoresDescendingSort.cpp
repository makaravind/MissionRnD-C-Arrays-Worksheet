/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that sorts these scores in descending order.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40).
Output for this will be [ { "stud3", 40 }, { "stud2", 30 }, { "stud1", 20 } ]

INPUTS: Array of structures of type student, length of array.

OUTPUT: Sort the array in descending order of scores.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

struct student {
	char name[10];
	int score;
};
int partition(student *A, int p, int r) {
	int x = A[p].score; // pivot
	int i = p;
	int j = r;
	while (true) {

		while (A[i].score > x) {
			i++;
		}

		while (A[j].score < x) {
			j--;
		}
		if (i < j) {
			int temp = A[i].score;
			A[i].score = A[j].score;
			A[j].score = temp;
		}
		else {
			return j;
		}
	}
}
void quicksort(student *A, int p, int r) {
	if (p < r) {
		int q = partition(A, p, r);
		quicksort(A, p, q);
		quicksort(A, q + 1, r);
	}
}
int IfAllSame(struct student *students, int len){
	//Same elements checking
	int ref = students[0].score;
	int flag = -1;
	for (int i = 1; i < len; i++)
		if (students[i].score != ref) return 1;
	return 0;
}
void * scoresDescendingSort(struct student *students, int len) {
	// init checking 
	if (students == NULL) return NULL;
	if (len < 0) return NULL;

	if(IfAllSame(students,len)) 
		quicksort(students, 0, len - 1);
	return students;
}