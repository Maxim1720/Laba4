#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL));
	int M[20], b = 0,i=0;
	printf("array condition:\n");

	for (i = 0;i < 20;i++)
		printf("\t|%02d|\n", 20 - i);
	printf("Our array: \n");
	for (i = 0; i < 20; i++) {
		M[i] = rand() % 20 + 1;
		printf("\t|%02d|\n", M[i]);
	}
	for ( i = 0;i < 20;i++) {
		if (M[i] != 20-i) {
			printf("the array does not match the condition\n");
			break;
		}
		else if (M[i] == 20-i) {
			printf("the array matches the condition");
		}
	}
	return 0;
}