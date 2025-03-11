#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void main() {
	int a;
	printf("Nhap vao so  nguyen a= ");
	scanf("%d", &a);
	if (a > 0) {
		printf("So %d la so duong\n", a);
	}
	else if (a < 0) {
		printf("So %d la so am\n", a);
	}
	else {
		printf("So %d la so 0\n", a);
	}
}