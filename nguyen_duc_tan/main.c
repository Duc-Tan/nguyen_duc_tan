#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

void main() {
	int a[10];
	int sum = 0;
	for (int i = 0; i < 10; i++) {
		printf("Nhap vao a[%d]= ", i);
		scanf("%d", &a[i]);
		sum += a[i];
	}
	printf("Tong cua mang la: %d", sum);
}