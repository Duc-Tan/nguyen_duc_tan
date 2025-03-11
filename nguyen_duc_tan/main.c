#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void main() {
	float a, b, c, del,x, x1, x2;
	printf("Nhap vao so a= ");
	scanf("%f", &a);
	printf("Nhap vao so b= ");
	scanf("%f", &b);
	printf("Nhap vao so c= ");
	scanf("%f", &c);

	if (a == 0) {
		printf("Phuong trinh bac nhat");
	}
	else {

		del = b * b - 4 * a * c;
		if (del < 0) {
			printf("Phuong trinh vo nghiem");
		}
		else if (del == 0) {
			x = -b / (2 * a);
			printf("Phuong trinh co nghiem kep x1=x2= %f", x);
		}
		else {
			x1 = (-b + sqrt(del)) / (2 * a);
			x2 = (-b - sqrt(del)) / (2 * a);
			printf("Phuong trinh co 2 nghiem phan biet x1= %f, x2= %f", x1, x2);
		}
	}
}