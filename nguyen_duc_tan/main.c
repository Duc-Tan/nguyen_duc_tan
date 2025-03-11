#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void main() {
	int a,b,c,max;
	printf("Nhap vao so a: ");
	scanf("%d", &a);
	printf("Nhap vao so b: ");
	scanf("%d", &b);
	printf("Nhap vao so c: ");
	scanf("%d", &c);

	max = a;
	if (max < b) {
		max = b;
	}
	if (max < c) {
		max = c;
	}
	printf("So lon nhat la: %d", max);
	
}