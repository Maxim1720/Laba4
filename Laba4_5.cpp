#include <stdio.h>
#include<stdlib.h>
#include<ctime>
#include<locale.h>
int ocenka(int a) {
	int m = 0;
	switch (a) {
	case 4:
		return 4;
		break;
	case 5:
		return 5;
		break;
	default:
		return 0;
		break;
	}
}

int main()
{
	setlocale(0, "");
	srand((unsigned int)time(NULL));
	int S[3][25][4], i, j, k,m=0;

	for (i = 0;i < 3;i++) {
		for (j = 0;j < 25;j++) {
			for (k = 0;k < 4;k++) {
				S[i][j][k] = rand() % 5 + 1;
				if (S[i][j][k] == 2 || S[i][j][k] == 3|| S[i][j][k] == 1) {
					srand((unsigned int)time(NULL)+i);
					S[i][j][k] = rand() %5 + 1;
				}
			}
		}
	}
	for (i = 0;i < 3;i++) {
		printf("\n");
		for (j = 0;j < 25;j++) {
			printf("\n");
			for (k = 0;k < 4;k++) {
				printf("S[%02d][%02d][%02d]=%d\t", i, j, k, S[i][j][k]);
			}
		}
	}
	int O[3] = { 0,0,0 }, H[3] = { 0,0,0 };
	for (i = 0;i < 3;i++) {
		for (j = 0;j < 25;j++) {
			for (k = 0;k < 4;k++) {
				m += ocenka(S[i][j][k]);
				if(m == 20){
					O[i]++;
				}
				if( m < 20 && m >= 16){
					H[i]++;
				}
			}
			m = 0;

		}
	}printf("\n\n");
	for (i = 0;i < 3;i++) {
		printf("в %d группе %d отличников \n", i + 1, O[i]);
	}printf("\n\n");
	for (i = 0;i < 3;i++) {
		printf("в %d группе %d хорошистов \n", i + 1, H[i]);
	}
	return 0;
}