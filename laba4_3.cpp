#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<ctime>

int main()
{
	srand(time(NULL));
	setlocale(0, "");
	double A[8][8]; int i, j;
	for (i = 0;i < 8;i++) {
		for (j = 0;j < 8;j++) {
			A[i][j] = rand() % 100 - 40.48;
		}
	}
	printf("Наш массив: \n");

	for (i = 0;i < 8;i++) {
		printf("\n");
		for (j = 0;j < 8;j++) {
			printf("A[%d][%d]=%.2lf\t", i, j, A[i][j]);
		}
	}
	double K[8];int l;
	for (j = 0, l = 0;j < 8;j++) {
		l = j;
		K[l] = A[7][j];
	}
	for (j = 0;j < 7;j++) {
		for (i = 0;i < 8;i++) {
				l = i;
				A[i][j] -= K[l];
		}
	}
	printf("\n\nРезультат преобразования: \n");
	for (i = 0;i < 8;i++) {
		printf("\n");
		for (j = 0;j < 8;j++) {
			printf("A[%d][%d]=%.2lf\t", i, j, A[i][j]);
		}
	}
	printf("\n\n");
	system("pause");
	return 0;
}