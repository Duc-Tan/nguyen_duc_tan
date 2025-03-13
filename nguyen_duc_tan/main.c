#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

void main() {
	int dv, ch, tr, ng;
	int n;
	printf("Nhap so nguyen n: ");
	scanf("%d", &n);
	dv = n % 10;
	ch = (n / 10) % 10;
	tr = (n / 100) % 10;
	ng = n / 1000;
	int a;
	for (int i = 0; i < 4; i++) {
		if (i == 0) a = ng;
		if (i == 1) a = tr;
		if (i == 2) a = ch;
		if (i == 3) a = dv;
		switch (a) {
		case 0: if (i == 1 && ng > 0) printf("Khong "); else if (i == 2 && dv > 0) printf("Le "); else if (n == 0) printf("Khong "); break;
		case 1: printf("Mot "); break;
		case 2: printf("Hai "); break;
		case 3: printf("Ba "); break;
		case 4: printf("Bon "); break;
		case 5: printf("Nam "); break;
		case 6: printf("Sau "); break;
		case 7: printf("Bay "); break;
		case 8: printf("Tam "); break;
		case 9: printf("Chin "); break;
		}
		switch (i) {
		case 0: if (ng > 0) printf("Ngan "); break;
		case 1: if (tr > 0 || (ng > 0 && (ch > 0 || dv > 0))) printf("Tram "); break;
		case 2: if (ch > 0) printf("Muoi "); break;
		case 3: printf("\n"); break;
		}
	}
}