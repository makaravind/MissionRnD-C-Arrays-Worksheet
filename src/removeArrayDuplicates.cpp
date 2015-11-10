/*
OVERVIEW:  given an array that has duplicate values remove all duplicate values.
E.g.: input: [1, 1, 2, 2, 3, 3], output [1, 2, 3]

INPUTS: Integer array and length of the array.

OUTPUT: Update input array by removing duplicate values.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Don't create new array, try to change the input array.
*/

#include <stdio.h>
#include<malloc.h>
struct node
{
	int value;
	node* left;
	node* right;
};
struct node* insert(struct node* r, int data)
{
	if (r == NULL)
	{
		r = (struct node*) malloc(sizeof(struct node));
		r->value = data;
		r->left = NULL;
		r->right = NULL;
	}
	else if (data == r->value) return r;
	else if (data < r->value){
		r->left = insert(r->left, data);
	}
	else {
		r->right = insert(r->right, data);
	}
	return r;

}
int preOrder(struct node* r, int *a, int n, int count)
{

	if (r != NULL){
	//	printf("%d ", r->value);
		a[count++] = r->value;
		preOrder(r->left, a, n, count);
		preOrder(r->right, a, n, count);
	}
	return count;
}
void * removeArrayDuplicates(int *Arr, int len)
{
	//init checking
	if (Arr == NULL) return NULL;
	if (len < 0) return NULL;

	struct node* root;
	root = NULL;
	static int count = 0;

	for (int i = 0; i < len; i++) {
		root = insert(root, Arr[i]);
	}

	len = preOrder(root, Arr, len, count);
	return NULL;
}