#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int main()
{
	srand(time_t(NULL));
	setlocale(0, "rus");
	int M[20], b = 0,i=0;
	printf("\tУсловия массива:\n");

	for (i = 0;i < 20;i++)
		printf("\t\t\tM[%d]=%d\n", i, 20 - i);
	for (i = 0; i < 20; i++) {
		M[i] = rand() % 20 + 1;
	}
	printf("\tНаш массив: \n");
	for ( i = 0;i < 20;i++)
		printf("M[%d]=%d\n", i, M[i]);
	for ( i = 0;i < 20;i++) {
		if (M[i] != 20-i) {
			printf("\tМассив не соответствует условиям\n");
			break;
		}
		else if (i == 19) {
			printf("Массив удовлетворяет условиям");
		}
	}
	return 0;
}