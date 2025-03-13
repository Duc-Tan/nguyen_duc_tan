#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

void main() {
	float S=0;
	float a, b, h;
	printf("Nhap vao a= ");
	scanf("%f", &a);
	printf("Nhap vao b= ");
	scanf("%f", &b);
	h = (b - a) / 1000;
	for (int i = 0; i < 1000; i++) {
		S += (pow(a + i * h, 2) + pow(a + (i + 1) * h, 2)) * h / 2;
	}
	printf("Tich phan tu a den b cua ham f(x)=x^2 la %f", S);
}