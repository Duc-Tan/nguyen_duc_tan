#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

void main() {
	int a[] = { 0,11,62,4,16,34,78,23,91,1,7 };
	int sum = 0;
	int dem = 0;
	float tbc = 0;
	int so_luong = sizeof(a) / sizeof(a[0]);
	for (int i = 0; i < so_luong; i++) {
		if (a[i] % 2 == 1) {
			sum += a[i];
			dem++;
		}
	}
	tbc = (float)sum / dem;
	printf("Trung binh cong cac so le trong mang la: %f\n", tbc);
}