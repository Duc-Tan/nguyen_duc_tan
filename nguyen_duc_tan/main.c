#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

void main() {
	int n;
	int so_tien_ban_dau;
	int so_tien_lai = 0;
	printf("Nhap so tien ban dau: ");
	scanf("%d", &so_tien_ban_dau);
	printf("Nhap so nam gui: ");
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		so_tien_lai = so_tien_ban_dau * pow((1 + 0.82), i);
		printf("So tien sau %d nam la: %d\n", i, so_tien_lai);
	}
	
}