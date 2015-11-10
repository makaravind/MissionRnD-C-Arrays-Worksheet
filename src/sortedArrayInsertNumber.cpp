/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
			E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use realloc to allocate memory.
*/

#include <stdio.h>
#include <malloc.h>
void Swap(int *a, int i, int *b){
	int t;
	t = a[i];
	a[i] = *b;
	*b = t;
}
int * sortedArrayInsertNumber(int *Arr, int len, int num)
{
	// init error checking
	if (Arr == NULL) return NULL;
	if (len < 0) return NULL;

	int i = 0;
	int temp = -1;

	if (Arr[0] > num) i = 0;
	else if (Arr[len - 1] < num){
		len++; // new length
		Arr = (int*)realloc(Arr, sizeof(int)*len);
		Arr[len-1] = num;
		return Arr;
	}
	else{
		while (i<len)
		{
			if (Arr[i] < num) i++;
			else if (Arr[i] == num) return NULL;
			else
				break;
		}
		
	}
	len++; // new length
	Arr = (int*)realloc(Arr, sizeof(int)*len);
	temp = Arr[i];
	for (int k = i + 1; k < len; k++)
	{
		int t;
		t = Arr[k];
		Arr[k] = temp;
		temp = t;
	}
	Arr[i] = num;
	return Arr;
}