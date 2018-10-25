#include "stdio.h"

void hanoi(int n, int from, int help, int to) {
	if (n > 1) hanoi(n - 1, from, to, help);
	printf("move %d from %c to %c\n", n, from, to);
	if (n > 1) hanoi(n - 1, help, from, to);
}

int main(int argc, char* argv[])
{
	int n;
	printf("Input plate number:\n");
	while (scanf_s("%d", &n) == 1)
		hanoi(n, 'A', 'B', 'C');
    return 0;
}