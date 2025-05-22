#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

typedef union {
	unsigned short x;
	unsigned char y[2];
}so_nguyen_t;

void in_8bit_cao_8bit_thap(unsigned short val) {
	so_nguyen_t a;
	a.x = val;
	printf("8 bit thap: %d\n", a.y[0]);
	printf("8 bit cao: %d\n", a.y[1]);
}

void main() {
	unsigned short value;
	printf("Nhap vao so nguyen 16 bit: ");
	scanf("%hd", &value);
	in_8bit_cao_8bit_thap(value);
}