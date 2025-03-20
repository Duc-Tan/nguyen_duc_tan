#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include "toan.h"

void main() {
	int a = cong(2, 3);
	int b = nhan(4, 11);
	float c = chia(5, 2);
	int d = tru(17, 5);
	printf("a = %d\n", a);
	printf("b = %d\n", b);
	printf("c = %f\n", c);
	printf("d = %d\n", d);
}