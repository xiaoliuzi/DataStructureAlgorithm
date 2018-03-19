#include "stdio.h"

void swap(int *a, int *b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void bubblesort1A(int A[], int n) {
	if (n <= 1) return;
	for (int i = 0; i < n; n--)
		for (int j = 0; j < n - 1; j++)
			if (A[j] > A[j + 1])
				swap(&A[j], &A[j + 1]);
}

int main(int argc, char* argv[])
{
	int a[] = { 5, 2, 7, 4, 6, 3, 1 };
	bubblesort1A(a, 7);
	for (int i = 0; i < 7; ++i)
		printf("%d ", a[i]);
    return 0;
}
