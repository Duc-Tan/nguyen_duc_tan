#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

void main() {
	char str[] = "dem ky tu space trong chuoi   ";
	int c = 0;
	int so_luong_space = 0;
	while (str[c] != 0) {
		if (str[c] == ' ')
			so_luong_space++;
		c++;
	}
	printf("So luong ky tu space: %d\n", so_luong_space);
}