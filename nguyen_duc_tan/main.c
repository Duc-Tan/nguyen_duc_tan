#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void main() {
	for (int i = 1; i < 11; i++) {
		for (int j = 2; j < 10; j++) {
			printf("%d * %d = %d\t", j, i, i * j);
		}
		printf("\n");
	}

}