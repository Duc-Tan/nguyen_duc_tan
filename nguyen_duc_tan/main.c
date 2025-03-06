#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void main() {
	float diem;
	printf("Nhap vao diem trung binh: ");
	scanf("%f", &diem);
	if (diem >= 8.0) {
		printf("Hoc sinh gioi");
	}
	else if (8.0 > diem && diem >= 6.5) {
		printf("Hoc sinh kha");
	}
	else if (6.5 > diem && diem >= 5.0) {
		printf("Hoc sinh trung binh");
	}
	else if (diem < 5.0) {
		printf("Hoc sinh yeu");
	}
}