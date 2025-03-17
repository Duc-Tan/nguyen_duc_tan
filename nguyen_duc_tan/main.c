#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

void main() {
	char str[] = "nguyen duc tan ";
	int c = 0;
	char in_hoa[sizeof(str)];
	while (str[c] != 0) {
		if (c==0 || str[c-1]==32) {
			if (str[c] >= 97 && str[c] <= 122) {
				in_hoa[c] = str[c] - 32;
			}
			else {
				in_hoa[c] = str[c];
			}
		}
		else {
			in_hoa[c] = str[c];
		}
		c++;
	}
	in_hoa[c] = 0;
	printf("%s\n",in_hoa);
}