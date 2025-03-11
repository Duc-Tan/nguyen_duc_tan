#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void main() {
    int k;
    int tien = 0;
    printf("Nhap so kWh su dung: ");
    scanf("%d", &k);

    if (k < 0) {
        printf("So kWh khong hop le\n");
    }
    else {
        if (k > 400) {
            tien += (k - 400) * 2927;
            k = 400;
        }
        if (k > 300) {
            tien += (k - 300) * 2834;
            k = 300;
        }
        if (k > 200) {
            tien += (k - 200) * 2536;
            k = 200;
        }
        if (k > 100) {
            tien += (k - 100) * 2014;
            k = 100;
        }
        if (k > 50) {
            tien += (k - 50) * 1734;
            k = 50;
        }
        if (k > 0) {
            tien += k * 1678;
        }

        printf("So tien phai tra la: %d VND\n", tien);
    }
}