#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

typedef struct {
	char ten[100];
	int tuoi;
	float diem_toan;
	float diem_van;
	float diem_tb;
	int xep_loai;
}hocsinh;

//Chuc nang: Nhap thong tin hoc sinh
//Input: Nhap mang hoc sinh, so luong hoc sinh
//Output: khong co
void nhap_hoc_sinh(hocsinh* hs, int so_luong) {
	getchar();
	for (int i = 0; i < so_luong; i++) {
		printf("Nhap ten hoc sinh thu %d: ", i + 1);
		gets(hs[i].ten);
		printf("Nhap tuoi hoc sinh thu %d: ", i + 1);
		scanf("%d", &hs[i].tuoi);
		printf("Nhap diem toan hoc sinh thu %d: ", i + 1);
		scanf("%f", &hs[i].diem_toan);
		printf("Nhap diem van hoc sinh thu %d: ", i + 1);
		scanf("%f", &hs[i].diem_van);
		getchar();
	}
}

//Chuc nang: In ra danh sach hoc sinh
//Input: Nhap mang hoc sinh, so luong hoc sinh
//Output: khong co
void in_hoc_sinh(hocsinh* hs, int so_luong) {
	for (int i = 0; i < so_luong; i++) {
		printf("Ten hoc sinh thu %d: %s\n", i + 1, hs[i].ten);
		printf("Tuoi hoc sinh thu %d: %d\n", i + 1, hs[i].tuoi);
		printf("Diem toan hoc sinh thu %d: %.2f\n", i + 1, hs[i].diem_toan);
		printf("Diem van hoc sinh thu %d: %.2f\n", i + 1, hs[i].diem_van);
	}
}

//Chuc nang: Tinh diem trung bin va xep loai cua hoc sinh
//Input: Nhap mang hoc sinh, so luong hoc sinh
//Output: khong co
void tinh_diem_xep_loai(hocsinh* hs, int so_luong) {
	for (int i = 0; i < so_luong; i++) {
		hs[i].diem_tb = (hs[i].diem_toan + hs[i].diem_van) / 2;
		if (hs[i].diem_tb >= 8) {
			hs[i].xep_loai = 0;
		}
		else if (hs[i].diem_tb >= 6.5) {
			hs[i].xep_loai = 1;
		}
		else if (hs[i].diem_tb >= 5) {
			hs[i].xep_loai = 2;
		}
		else {
			hs[i].xep_loai = 3;
		}
	}
}

//Chuc nang: In hoc sinh co diem trung binh cao nhat
//Input: Nhap mang hoc sinh, so luong hoc sinh
//Output: khong co
void in_hoc_sinh_dtb_cao_nhat(hocsinh* hs, int so_luong) {
	float max = hs[0].diem_tb;
	for (int i = 0; i < so_luong; i++) {
		if (hs[i].diem_tb > max) {
			max = hs[i].diem_tb;
		}
	}
	for (int i = 0; i < so_luong; i++) {
		if (hs[i].diem_tb == max) {
			printf("Ten hoc sinh co diem trung binh cao nhat: %s\n", hs[i].ten);
			printf("Tuoi hoc sinh co diem trung binh cao nhat: %d\n", hs[i].tuoi);
			printf("Diem trung binh cao nhat: %.2f\n", hs[i].diem_tb);
			printf("Xep loai hoc sinh (0=gioi, 1=kha, 2=trung binh, 3=yeu): %d\n", hs[i].xep_loai);
		}
	}
}

//Chuc nang: Xep loai hoc sinh tu cao den thap
//Input: Nhap mang hoc sinh, so luong hoc sinh
//Output: khong co
void xep_loai_hoc_sinh(hocsinh* hs, int so_luong) {
	hocsinh temp;
	for (int i = 0; i < so_luong - 1; i++) {
		for (int j = i + 1; j < so_luong; j++) {
			if (hs[i].diem_tb < hs[j].diem_tb) {
				temp = hs[i];
				hs[i] = hs[j];
				hs[j] = temp;
			}
		}
	}
	for (int i = 0; i < so_luong; i++) {
		printf("Ten hoc sinh thu %d: %s\n", i + 1, hs[i].ten);
		printf("Diem trung binh hoc sinh thu %d: %.2f\n", i + 1, hs[i].diem_tb);
		printf("Xep loai hoc sinh thu %d (0=gioi, 1=kha, 2=trung binh, 3=yeu): %d\n", i + 1, hs[i].xep_loai);
	}
}

void main() {
	hocsinh hs[100];
	int n;
	printf("Nhap so luong hoc sinh: ");
	scanf("%d", &n);
	nhap_hoc_sinh(hs, n);
	in_hoc_sinh(hs, n);
	tinh_diem_xep_loai(hs, n);
	in_hoc_sinh_dtb_cao_nhat(hs, n);
	xep_loai_hoc_sinh(hs, n);
}