#include <stdio.h>
#include <stdlib.h>
#include<locale.h>
#include<time.h>
int main() {
	setlocale(0,"");
	srand((unsigned int)time(NULL));
	int* A = NULL, i, m, k,n;

	printf("Введите размер массива: ");
	scanf_s("%d", &n);
	A = (int*)malloc(n * sizeof(int));

	for (i = 0; i < n; i++) {
		A[i] = rand() % 100 - 40;
	}
	printf("Исходный массив: \n");
	for (i = 0; i < n; i++) {
		printf("\tA[%02d] = %3d\n", i, A[i]);
	}
	for (i = 0, m = 0; i < n; i++) {
		if (A[i] < 0) {
			m++;
		}
	}
	int* M = NULL;
	if (m == 0) {
		printf("\nМассив не изменится, т.к. отсутствуют отрицательные числа\n");
	}
	else if (m == 1) {
		printf("\nМассив не изменится, т.к. имеет всего одно отрицательное число\n");
	}
	else {
		M = (int*)malloc(m * sizeof(int));
		for (i = 0, k = 0; i < n && k < m; i++) {
			if (A[i] < 0) {
				M[k] = A[i];
				k++;
			}
		}
		M[0] = M[0] xor M[k - 1];
		M[k - 1] = M[0] xor M[k-1];
		M[0] = M[0] xor M[k - 1];

		for (i = 0, k = 0; i < n && k < m; i++) {
			if (A[i] < 0) {
				A[i] = M[k];
				k++;
			}
		}
		printf("\nРезультат: \n");
		for (i = 0; i < n; i++) {
			printf("\tA[%02d] = %3d\n", i, A[i]);
		}

		free(A);
		free(M);
	}
	system("pause");
	return 0;

}
