/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <malloc.h>
#include<limits.h>

struct student {
	char *name;
	int score;
};
int partition1(student *A, int p, int r) {
	int x = A[p].score; // pivot
	int i = p;
	int j = r;
	while (true) {

		while (A[i].score > x) {
			i++;
		}

		while (A[j].score  < x) {
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
void quicksort1(student *A, int p, int r) {
	if (p < r) {
		int q = partition1(A, p, r);
		quicksort1(A, p, q);
		quicksort1(A, q + 1, r);
	}
}
struct student ** topKStudents(struct student *students, int len, int K) {
	if (students == NULL) return NULL;
	if (len < 0) return NULL;
	if (K <= 0) return NULL;

	//creating return pointer
	struct student **top;
	top = (struct student **) malloc(K * sizeof(struct student));
	for (int i = 0; i < K; i++)
		top[i] = (struct student *)malloc(sizeof(struct student) * 1);

	// if K greater than len
	if (K > len) {
		for (int i = 0; i < len; i++)
			top[i] = &students[i];
		return top;
	}

	int max;
	int maxid;
	int ref = INT_MAX;
	//int result[100];

	for (int j = 0; j < K; j++)
	{
	max = INT_MIN;
	for ( int i = 0; i < len; i++){
	if (students[i].score > max && students[i].score < ref) {
	max = students[i].score;
	maxid = i;
	}

	}
	ref = max;
	top[j] = &students[maxid];
	//result[j] = max;
	}

	/*quicksort1(students, 0, len - 1);

	for (int i = len - 1; i <= K; i++){
		top[i] = &students[i];
	}*/
	return top;
}
