#include<time.h>
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	srand(time(0));
	int Q[6][8],k=0,l=0;

	for (int j = 0;j < 8;j++) {
		printf("\n");
		for (int i = 0;i < 6;i++) {
			Q[i][j] = rand() % 50 - 25;
			printf("|%+03d| ", Q[i][j]);
			if (Q[i][j] < 0)
				k++;
		}
	}
	int* K;
	K= (int*)calloc(k, sizeof(int));
	for (int j = 0;j < 8;j++) {
		for (int i = 0;i < 6;i++) {	
			if (Q[i][j] < 0 && l < k) {
				K[l] = Q[i][j];
				l++;
			}	
		}
	}printf("\n\n");
	for (int i = 0;i < k;i++) {
		if (i % 6 == 0)printf("\n");
		printf("|%03d| ", K[i]);
	}
	free (K);
	return 0;
}