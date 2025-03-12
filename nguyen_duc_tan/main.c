#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void main() {
	int n;
	int sum = 0;
	printf("Nhap vao so n: ");
	scanf("%d", &n);
	for (int i = 0; i <= n; i++) {
		if (i % 2 == 0)
			sum += i;
	}
	printf("Tong %d so tu nhien chan dau tien la: %d\n", n,sum);

}