#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef enum {
	NAM,
	NU
}gioi_tinh_t;
char* gioi_tinh_t_str[] = { "NAM", "NU" };

typedef enum {
	GIOI,
	KHA,
	TRUNG_BINH,
	YEU
}loai_t;
char* loai_t_str[] = { "GIOI", "KHA", "TRUNG_BINH", "YEU" };

typedef struct {
	char* ten;
	int tuoi;
	gioi_tinh_t gioitinh;
	float diem_toan;
	float diem_van;
	float diem_tb;
	loai_t loai;
} hocsinh;

//Chuc nang: tinh diem trung binh va xep loai
//Input:hocsinh* hs
//Output: khong co
void tinh_diem_xep_loai(hocsinh* hs, int n) {
	for (int i = 0; i < n; i++) {
		hs[i].diem_tb = (hs[i].diem_toan + hs[i].diem_van) / 2;
		if (hs[i].diem_tb >= 8) {
			hs[i].loai = GIOI;
		}
		else if (hs[i].diem_tb >= 6.5) {
			hs[i].loai = KHA;
		}
		else if (hs[i].diem_tb >= 5) {
			hs[i].loai = TRUNG_BINH;
		}
		else {
			hs[i].loai = YEU;
		}
	}
}

//Chuc nang: In ra danh sach hoc sinh
 //Input: Nhap mang hoc sinh, so luong hoc sinh
 //Output: khong co
void in_hoc_sinh(hocsinh* hs, int so_luong) {
	for (int i = 0; i < so_luong; i++) {
		printf("Ten: %s\n", hs[i].ten);
		printf("Tuoi: %d\n", hs[i].tuoi);
		printf("Gioi tinh: %s\n", gioi_tinh_t_str[hs[i].gioitinh]);
		printf("Diem toan: %.2f\n", hs[i].diem_toan);
		printf("Diem van: %.2f\n", hs[i].diem_van);
		printf("Diem trung binh: %.2f\n", hs[i].diem_tb);
		printf("Xep loai: %s\n", loai_t_str[hs[i].loai]);
	}
}

void main() {
	hocsinh arr[] = {
		{"Nguyen Van A", 20, NAM, 8.5, 9},
		{"Nguyen Thi B", 20, NU, 7.5, 8},
		{"Nguyen Van C", 20, NAM, 6.5, 7},
	};
	tinh_diem_xep_loai(arr, 3);
	in_hoc_sinh(arr, 3);
}