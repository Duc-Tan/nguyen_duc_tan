#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

void main() {
	int a[] = { 7,3,27,92,0,1,5,12,103,90,6,13,11 };
	int so_luong = sizeof(a) / sizeof(a[0]);
	
	for (int i = 0; i < so_luong; i++) {
		for (int j = i + 1; j < so_luong; j++) {
			if (a[i] > a[j]) {
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	for (int i = 0; i < so_luong; i++) {
		printf("%d ", a[i]);
	}
}