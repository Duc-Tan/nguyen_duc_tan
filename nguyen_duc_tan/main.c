#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void main() {
	int n;
	printf("Nhap vao so  nguyen n= ");
	scanf("%d", &n);
	if (n%2==0) {
		printf("So %d la so CHAN\n", n);
	}
	
	else {
		printf("So %d la so LE\n", n);
	}
}