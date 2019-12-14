#include<stdio.h>
#include<stdlib.h>
#include<ctime>
#include<locale.h>

int main(void) {
	srand((unsigned int)time(NULL));
	setlocale(0, "");
	int l = 0, m, n;
	printf("enter the size of the matrix:\n\n\tString amount: ");
	scanf_s("%d", &n);
	printf("\n\tColumn amount: ");
	scanf_s("%d", &m);

	int** Q;
	Q = (int**)calloc(n,sizeof(int*));
	if (Q) {
		for (int i = 0;i < n;i++)
			Q[i] = (int*)calloc(m, sizeof(int));
		for (int i = 0;i < n;i++) {
			printf("\n");
			for (int j = 0;j < m;j++) {
				Q[i][j] = rand() % 50 - 20;
				printf("|%+03d| ", Q[i][j]);
				if (Q[i][j] < 0)
					l++;
			}
		}
	}
	printf("\n\n\n");
	int* K;
	K = (int*)calloc(l, sizeof(int));
	if (K) {
		int k = 0;
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < m && k < l;j++) {
				if (Q[i][j] < 0) {
					K[k] = Q[i][j];
					if (k % l == 0)printf("\n");
					printf("|%+03d| ", K[k]);
					k++;
					
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
			free(Q[i]);
	free(Q),(K);
	return 0;
}