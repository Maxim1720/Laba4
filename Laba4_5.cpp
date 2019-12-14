#include <stdio.h>
#include<stdlib.h>
#include<ctime>
#include<locale.h>
int grade(int a) {
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
	srand(time(NULL));
	int S[3][25][4];

	for (int i = 0;i < 3;i++) {
		printf("\n\n");
		for (int k = 0;k < 4;k++) {
			printf("\n");
			for (int j = 0;j < 25;j++) {
				S[i][j][k] = rand() % 5 + 1;
				printf("|%d| ", S[i][j][k]);
			}
		}
	}
	
	for (int i = 0;i < 3;i++) {
		int amount_otl = 0, amount_hor = 0;
		for (int j = 0;j < 25;j++) {
			int count = 0;
			for (int k = 0;k < 4;k++) {
				count += grade(S[i][j][k]);
			}
			if (count == 20) {
				amount_otl++;
			}
			if (count < 20 && count>16) {
				amount_hor++;
			}
		}
		if (amount_otl|| amount_hor) {
			printf("\nin %d group %d otlichnikov and %d horoshistov\n", i+1, amount_otl, amount_hor);
		}
	}
}