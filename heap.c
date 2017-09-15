#include <stdio.h>

int x[] = {0, 18, 20, 15, 29, 23, 17, 22, 35, 40, 26, 51, 19};
int y[] = {0, 12, 20, 15, 29, 23, 17, 22, 35, 40, 26, 51, 19, 13};

void siftup(int n)
{
	int i, j, temp;

	i = n;
	temp = y[i];
	while (i > 1) {
		j = i / 2;

		if (y[j] <= temp)
			break;

		y[i] = y[j];
		i = j;
	}
	y[i] = temp;
}


void siftdown(int n)
{
	int i, j, temp;

	i = 1;
	temp = x[i];
	for (;;) {
		j = 2 * i;

		if (j > n)
			break;

		if ((j + 1 <= n) && (x[j + 1] < x[j]))
			j++;

		if (temp <= x[j])
			break;

		x[i] = x[j];
		i = j;
	}
	x[i] = temp;
}


int main(int argc, char *argv[])
{
	int i, n;

	n = sizeof(x) / sizeof(int) - 1;
	siftdown(n);
	for (i = 1; i <= n; i++)
		printf("%3d\n", x[i]);
	printf("\n");

	n = sizeof(y) / sizeof(int) - 1;
	siftup(n);
	for (i = 1; i <= n; i++)
		printf("%3d\n", y[i]);

	return 0;
}
