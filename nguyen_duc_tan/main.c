#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void main() {
	int n;
	int gt = 1;
	printf("Nhap n: ");
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		if (n == 0) {
			gt = 1;
		}
		else {
			gt *= i;
		}
	}
	printf("Giai thua cua %d la: %d", n, gt);
}