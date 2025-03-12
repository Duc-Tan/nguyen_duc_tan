#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void main() {
	int n;
	int m = 0;
	int error = 0;
	do {
		printf("Nhap vao so: ");
		scanf("%d", &n);
		if (n != m) {
			printf("Vui long nhap lai\n");
			error++;
			if (error == 5) {
				break;
			}
		}
	} while (n != m);

	
}