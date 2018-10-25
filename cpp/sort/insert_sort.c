#include "stdio.h"

void insert_sort(int a[], int n)
{
	for (int j = 1; j < n; ++j) {
		int key = a[j];
		int i = j - 1;
		while (i >= 0 && a[i] > key) {
			a[i + 1] = a[i];
			i -= 1;
		}
		a[i + 1] = key;
	}
}

int main(int argc, char* argv[])
{
	int a[] = { 5, 2, 4, 6, 1, 3 };
	printf("before sort:\n");
	for (int i = 0; i < 6; ++i) {
		printf("%d ", a[i]);
	}
	printf("\n");
	insert_sort(a, 6);
	printf("after sort:\n");
	for (int i = 0; i < 6; ++i) {
		printf("%d ", a[i]);
	}
	printf("\n");
    return 0;
}