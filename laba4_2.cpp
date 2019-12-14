#include <stdio.h>
#include <stdlib.h>
#include<time.h>
int main() {
	srand((unsigned)time(NULL));
	int* A, n;
	int* f_neg=NULL, *e_neg=NULL;
	scanf_s("%d", &n);
	A = (int*)calloc(n, sizeof(int));
	if (A) {
		printf("\n\n");
		for (int i = 0;i < n;i++) {
			A[i] = rand() % 20 - 10;
			printf("|%d| ", A[i]);
		}
		printf("\n\n");
		for (int i = 0;i < n;i++) {
			if (A[i] < 0)
				f_neg = (A + i);
		}

		for (int i = n - 1;i >= 0;--i) {
			if (A[i] < 0)
				e_neg = (A + i);
		}
		
		if (f_neg && e_neg) {
			int tmp = 0;
			tmp = *f_neg;
			*f_neg = *e_neg;
			*e_neg = tmp;
		}
		for (int i = 0;i < n;i++)
			printf("|%d| ", A[i]);
		if (!f_neg && !e_neg)
			printf("\nthere are no negative numbers.\n");
		if (f_neg == e_neg)
			printf("\n\nthere is only one negative number.\n");
	}

	free(A);
	return 0;
}
