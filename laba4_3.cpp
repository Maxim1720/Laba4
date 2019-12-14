#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	srand(time(NULL));
	double A[8][8];
	printf("Our array: \n");
	for (int i = 0;i < 8;i++) {
		printf("\n");
		for (int j = 0;j < 8;j++) {
			A[i][j] = rand() % 100 - 40.48;
			printf("|%+5.1lf|\t", A[i][j]);
		}
	}
	for (int i = 0,j=0;i < 8 && j<7;i++) {
		A[i][j] -= A[7][i];
		if (i == 7) {
			i = 0;j++;
		}
	}
	printf("\n\nconversion result: \n");
	for (int i = 0;i < 8;i++) {
		printf("\n");
		for (int j = 0;j < 8;j++) {
			printf("|%+5.1lf|\t", A[i][j]);
		}
	}
	return 0;
}