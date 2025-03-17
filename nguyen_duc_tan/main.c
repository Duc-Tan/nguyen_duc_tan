#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

void main() {
	int a[] = { 7,3,27,92,0,1,5,12,53,90,6,13,11 };
	int so_luong = sizeof(a) / sizeof(a[0]);
	printf("Cac so nguyen to trong mang la: ");
	for (int i = 0; i < so_luong; i++) {
		int dem = 0;
		for (int j = 1; j <= a[i]; j++) {
			if (a[i] % j == 0) {
				dem++;
			}
		}
		if (dem == 2) {
			printf("%d ", a[i]);
		}
	}
}