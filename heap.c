#include <stdio.h>

int x[] = {0, 18, 20, 15, 29, 23, 17, 22, 35, 40, 26, 51, 19};

void siftdown(int n)
{
	int i, j, k, temp;

	i = 1;
	temp = x[i];
	for (;;) {
		j = 2 * i;
		k = i;

		if (j > n)
			break;

		if (temp > x[j])
			k = j;

		j++;
		if (j > n) {
			if (k != i)
				x[i] = x[k];
			break;
		}

		if ((temp > x[j]) && (x[j - 1] > x[j]))
			k = j;
		
		if (k == i)
			break;

		x[i] = x[k];
	}
	x[k] = temp;
}


int main(int argc, char *argv[])
{
	int i;
	int n = sizeof(x) / sizeof(int) - 1;

	siftdown(n);
	for (i = 1; i <= n; i++)
		printf("%3d\n", x[i]);

	return 0;
}
