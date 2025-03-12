#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

void main() {
	int a,b;
	int max = 0;
	printf("Nhap vao so nguyen A: ");
	scanf("%d", &a);
	printf("Nhap vao so nguyen B: ");
	scanf("%d", &b);
	for (int i = 1; i <= a; i++) {
		if (a % i == 0 && b % i == 0) {
			if (i > max) {
				max = i;
			}
		}
	}
	printf("UCLN cua %d va %d la: %d\n", a, b, max);
}