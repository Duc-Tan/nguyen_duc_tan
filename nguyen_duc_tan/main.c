#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

void main() {
	int a[10] = { 1,3,5,7,9,1,9,4,1,6 };
	int max = 0;
	for (int i = 0; i < 10; i++) {
		if (a[i] > max) {
			max = a[i];
		}
	}
	for (int i = 0; i < 10; i++) {
		if (a[i] == max) {
			printf("Vi tri cua so lon nhat la %d\n", i);
		}
	}
}