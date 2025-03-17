#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

void main() {
	int a[] = { 7,3,27,92,0,1,5,12,103,90,6,13,11 };
	int max = 0;
	int so_luong = sizeof(a) / sizeof(a[0]);
	
	for (int i = 0; i < so_luong; i++) {
		if (max < a[i]) 
			max = a[i];
	}
	printf("Gia tri lon nhat cua mang la: %d", max);
}