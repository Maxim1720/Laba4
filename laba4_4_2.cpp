#include<stdio.h>
#include<stdlib.h>
#include<ctime>
#include<locale.h>

int main(void) {
	srand((unsigned int)time(NULL));
	setlocale(0, "");
	int i, j, * K, l = 0, m, n;
	int **Q;

	printf("Введите размер матрицы:\n\n\tКоличество строк: ");
	scanf_s("%d", &n);
	printf("\n\tКоличество столбцов: ");
	scanf_s("%d", &m);

	Q = (int**)malloc(n * sizeof(int*));
	for (i = 0;i < n;i++) {
			Q[i] = (int*)malloc(m * sizeof(int));
	}

	for (i = 0;i < n;i++) {
		for (j = 0;j < m;j++) {
			if (i < n && j<m) {
				Q[i][j] = rand() % 50 - 20;
			}
		}
	}
	for (i = 0;i < n;i++) {
		printf("\n");
		for (j = 0;j < m;j++) {
				printf("Q[%d][%d]=%d\t", i, j, Q[i][j]);
		}
	}
	for (i = 0;i < n;i++) {
		for (j = 0;j < m;j++) {
			if (Q[i][j] < 0) {
				l++;
			}
		}
	}
	K = (int*)malloc(l * sizeof(int));
	for (i = 0,l=0;i < n;i++) {
		for (j = 0;j < m;j++) {
			if (Q[i][j] < 0) {
				K[l] = Q[i][j];
				l++;
			}
		}
	}
	printf("\n");
	for (i = 0;i < l;i++) {
		printf("\nK[%d] = %d\t", i, K[i]);
	}

	for (i = n - 1; i > 0; i--) {
		free(Q[i]);
	}
	free(Q),(K);
	return 0;
}