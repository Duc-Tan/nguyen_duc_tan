#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

void main() {
	char str[] = "nguyen duc tan ";
	int c = 0;
	while (str[c] != 0) {
		if (str[c] == 99) {
			printf("Vi tri cua ki tu c la: %d\n", c);
			printf("Dia chi cua ki tu c la: %p\n", &c);
		}
		c++;
	}
}