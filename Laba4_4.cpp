#include<ctime>
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	srand((unsigned int)time(0));
	int Q[6][8],i,j,k=0,l=0;

	for (j = 0;j < 8;j++) {
		for (i = 0;i < 6;i++) {
			Q[i][j] = rand() % 50 - 25;
		}
	}
	for (j = 0;j < 8;j++) {
		printf("\n");
		for (i = 0;i < 6;i++) {
			printf("Q[%d][%d]=%d\t", i, j, Q[i][j]);
		}
	}
	for (i = 0;i < 6;i++) {
		for (j = 0;j < 8;j++) {
			if (Q[i][j] < 0) {
				k++;
			}
		}
	}
	int* K=NULL;
	K= (int*)malloc(k * sizeof(int));
	for (j = 0;j < 8;j++) {
		for (i = 0;i < 6;i++) {
			if (Q[i][j] < 0 && l<k) {
				K[l] = Q[i][j];
				l++;
			}
		}
	}printf("\n\n");
	for (int m=0, l = 0;l < k;l++) {
		printf("%d\t",K[l]);
		m++;
		if (m==6) {
			//printf("\n");
			m = 0;
		}
	}
	printf("\n");
	free (K);
	system("pause");
	return 0;
}