#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

void main() {
	int n;
	printf("Nhap vao so:");
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int dem = 0;
		for (int j = 1; j <= i; j++) {
			if (i%j == 0)
				dem++;
		}
		if (dem == 2)
			printf("%d ", i);
	}
}