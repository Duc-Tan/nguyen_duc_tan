#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

void main() {
	char str[] = "     this is     a    string    ";
	int c = 0;
	int chu = 0;
	while (str[c] != 0) {
		if ((str[c] != 32) && (str[c+1] == 32 || str[c + 1] == 0)) {
			chu++;
		}
		c++;
	}
	printf("So tu trong chuoi: %d\n",chu);
}