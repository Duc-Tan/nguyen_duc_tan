#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

//in ra so le
//input: nhap mang
//output: khong co
void in_so_le(int* mang, int so_luong) {
	printf("so le cua mang la: ");
	for (int i = 0; i < so_luong; i++) {
		if (*(mang + i) % 2 != 0) {
			printf("%d ", *(mang + i));
		}
	}
	printf("\n");
}

//in ra so nguyen to trong mang
//input: nhap mang
//output: khong co
void in_so_nguyen_to(int* mang, int so_luong) {
	printf("so nguyen to cua mang la: ");
	for (int i = 0; i < so_luong; i++) {
		int dem = 0;
		for (int j = 1; j <= *(mang + i); j++) {
			if (*(mang + i) % j == 0) {
				dem++;
			}
		}
		if (dem == 2) {
			printf("%d ", *(mang + i));
		}
	}
}

//hoan vi 2 so nguyen
//input: 2 so nguyen
//output: khong co
void hoan_vi(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

//sap xep mang tang dan
//input: nhap mang
//output: khong co
void mang_tang_dan(int* mang, int so_luong) {
	for (int i = 0; i < so_luong; i++) {
		for (int j = i + 1; j < so_luong; j++) {
			if (*(mang + i) > *(mang + j)) {
				hoan_vi(mang + i, mang + j);
			}
		}
	}
}

void main() {
	int a[] = { 0, 7, 9, 6, 11, 17, 52, 90, 19 };
	in_so_le(a, 9);
	in_so_nguyen_to(a, 9);
	mang_tang_dan(a, 9);
}