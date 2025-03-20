#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
//in ra so le
//input: nhap mang
//output: khong co
void in_so_le(int* dia_chi, int so_luong) {
	for (int i = 0; i < so_luong; i++) {
		if(*(dia_chi+i) % 2 != 0) {
			printf("%d ", *(dia_chi+i));
		}
	}
}
void main() {
	int a[] = {0, 7, 9, 6, 12, 17, 52, 90, 19};
	in_so_le(a, 9);
}
