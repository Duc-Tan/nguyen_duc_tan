#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

// Xay dung kieu du lieu mo ta doi tuong hoc sinh
// ten, tuoi, diem toan, diem van, diem trung binh (xep loai: 0=gioi, 1=kha, 2=trung binh, 3=yeu)
typedef struct {
	char* ten;
	int tuoi;
	float diemtoan;
	float diemvan;
	float diemtrungbinh;
	int xeploai;
} hocsinh;

//Chuc nang: Tinh diem trung binh va xep loai hoc luc cua hoc sinh
//Input: 
// hocsinh* mang
// int n: so luong hoc sinh
//Output: khong co
void tinhdiem(hocsinh* mang, int n) {
	for (int i = 0; i < n; i++) {
		mang[i].diemtrungbinh = (mang[i].diemtoan + mang[i].diemvan) / 2;
		if (mang[i].diemtrungbinh >= 8) {
			mang[i].xeploai = 0;
		}
		else if (mang[i].diemtrungbinh >= 6.5) {
			mang[i].xeploai = 1;
		}
		else if (mang[i].diemtrungbinh >= 5) {
			mang[i].xeploai = 2;
		}
		else {
			mang[i].xeploai = 3;
		}
	}
}

// Chuc nang: Tim hoc sinh co diem trung binh cao nhat
// Input:
//hocsinh* mang
// int n: so luong hoc sinh
// Output: hocsinh- co diem trung binh cao nhat(gom tat ca thong tin)
hocsinh timhocsinhcaonhat(hocsinh* mang, int n) {
	hocsinh hsmax = mang[0];
	for (int i = 1; i < n; i++) {
		if (mang[i].diemtrungbinh > hsmax.diemtrungbinh) {
			hsmax = mang[i];
		}
	}
	return hsmax;
}

void main() {
	hocsinh hs[] = {
		{"Nguyen Van A", 18, 8.5, 7.5, 0, 0},
		{"Nguyen Van B", 18, 7.5, 8.5, 0, 0},
		{"Nguyen Van C", 18, 6.5, 6.5, 0, 0},
		{"Nguyen Van D", 18, 5.5, 5.5, 0, 0},
		{"Nguyen Van E", 18, 4.5, 4.5, 0, 0}
	};
	tinhdiem(hs, 5);
	hocsinh hsmax=timhocsinhcaonhat(hs, 5);
	printf("Hoc sinh co diem trung binh cao nhat la: %s\n", hsmax.ten);
}