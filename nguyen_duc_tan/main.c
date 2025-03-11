#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void main() {
    double luong;
    double thue = 0;
    printf("Nhap so luong cua ban: ");
    scanf("%lf", &luong);

    if (luong < 0) {
        printf("So luong khong hop le\n");
    }
    else {
        if (luong > 18000000) {
            thue += (luong - 18000000) * 0.2;
            luong = 18000000;
        }
        if (luong >= 10000000) {
            thue += (luong - 1000000) * 0.15;
            luong = 10000000;
        }
        if (luong > 5000000) {
            thue += (luong - 5000000) * 0.1;
            luong = 5000000;
        }
        if (luong <= 5000000) {
            thue += luong * 0.05;
        }

        printf("So thue phai nop la: %lf VND\n", thue);
    }
}