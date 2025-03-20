#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

// dem ky tu trong chuoi
// input: chuoi
// output: khong co
void dem_ky_tu(char* s) {
	int dem = 0;
	int i = 0;
	while (*(s + i) != 0) {
		if (*(s + i) > 32)
			dem++;
		i++;
	}
	printf("So ky tu trong chuoi la: %d", dem);
}

// dem ky tu space
// input: chuoi
// output: khong co
void so_ky_tu_space(char* s) {
	int dem = 0;
	int i = 0;
	while (*(s + i) != 0) {
		if (*(s + i) == 32)
			dem++;
		i++;
	}
	printf("\nSo ky tu space trong chuoi la: %d", dem);
}

// chuyen chu thuong thanh chu hoa
// input: chuoi
// output: khong co
void in_hoa(char* s) {
	int i = 0;
	while (*(s + i) != 0) {
		if (*(s + i) > 96 && *(s + i) < 123)
			*(s + i) -= 32;
		i++;

	}
	printf("\n%s", s);
}

// dem so tu trong chuoi
// input: chuoi
// output: so tu
void dem_so_tu(char* s) {
	int dem = 0;
	int i = 0;
	while (*(s + i) != 0) {
		if (s[i] != 32 && (s[i + 1] == 32 || s[i + 1] == 0))
			dem++;
		i++;
	}
	printf("\nSo tu trong chuoi la: %d", dem);
}

// in hoa ky tu dau tien cua moi tu
// input: chuoi
// output: khong co
void ky_tu_dau(char* s) {
	int i = 0;
	while (*(s + i) != 0) {
		if (i == 0 || *(s + i - 1) == 32) {
			if (*(s + i) > 96 && *(s + i) < 123)
				*(s + i) -= 32;
		}
		i++;
	}
	printf("\n%s", s);
}

// tim ky tu c
// input: chuoi, ky tu c
// output: vi tri ky tu c
int tim_vi_tri_c(char* s) {
	int i = 0;
	while (*(s + i) != 0) {
		if (*(s + i) == 'c')
			return i;
		i++;
	}
	return -1;
}

void main() {
	char str[] = "xin chao moi nguoi ";
	dem_ky_tu(str);
	so_ky_tu_space(str);
	//in_hoa(str);
	dem_so_tu(str);
	//ky_tu_dau(str);
	int x=tim_vi_tri_c(str);
	printf("\nVi tri c la: %d", x);
}