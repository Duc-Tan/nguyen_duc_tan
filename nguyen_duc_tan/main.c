#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

void main() {
	int a[] = { 7,3,78,92,0,1,5,12,53,90,6,13,11 };
	int so_luong = sizeof(a) / sizeof(a[0]);
	printf("Cac gia tri le trong mang la: ");
	for (int i = 0; i < so_luong; i++) {
		if (a[i] % 2 == 1) {
			printf("%d ", a[i]);
		}
		
	}
}