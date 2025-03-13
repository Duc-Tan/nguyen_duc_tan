#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

void main() {
	char str[] = "xin chao";
	int c=0;
	while (str[c]!='\0') {
		printf("%c", str[c]);
		c++;
		printf(" : %d\n", c);
	}
}