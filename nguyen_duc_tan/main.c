#include<stdio.h>
#include<stdlib.h>

typedef struct {
	char ten[50];
	int tuoi;
	char gioitinh[4];
	float diem_van;
	float diem_toan;
	float diem_tb;
}HocSinh;

//Chuc nang: tinh diem trung binh
//Input: HocSinh* hs, int so_luong
//Output: float tinh_diem_tb
float tinh_diem_tb(float a, float b) {
	float tb = (a + b) / 2;
	return tb;
}

//Chuc nang: in ra hoc sinh co diem trung binh cao nhat
//Input: HocSinh* hs, int so_luong
//Output: void
void in_hsmax(HocSinh* hs, int so_luong)
{
	int max = 0;
	for (int i = 1; i < so_luong; i++) {
		if (hs[i].diem_tb > hs[max].diem_tb) {
			max = i;
		}
	}
	HocSinh hsmax = hs[max];
	printf("Ten: %s\n", hs[max].ten);
	printf("Tuoi: %d\n", hs[max].tuoi);
	printf("Gioi Tinh: %s\n", hs[max].gioitinh);
	printf("Diem Van: %.2f\n", hs[max].diem_van);
	printf("Diem Toan: %.2f\n", hs[max].diem_toan);
	printf("Diem Trung Binh: %.2f\n", hs[max].diem_tb);
}

//Chuc nang: sap xep hoc sinh theo diem trung binh giam dan
//Input: HocSinh* hs, int so_luong
////Output: void
void sap_xep_hoc_sinh_cao_thap(HocSinh* hs, int so_luong) {
	for (int i = 0; i < so_luong; i++) {
		for (int j = i + 1; j < so_luong; j++) {
			if (hs[i].diem_tb < hs[j].diem_tb) {
				HocSinh temp = hs[i];
				hs[i] = hs[j];
				hs[j] = temp;
			}
		}
	}
	printf("Ten\t\tTuoi\tGioi Tinh\tDiem Van\tDiem Toan\tDiem Trung Binh\n");
	for (int i = 0; i < so_luong; i++) {
		printf("%s\t", hs[i].ten);
		printf("%d\t", hs[i].tuoi);
		printf("%s\t\t", hs[i].gioitinh);
		printf("%.2f\t\t", hs[i].diem_van);
		printf("%.2f\t\t", hs[i].diem_toan);
		printf(" %.2f\n", hs[i].diem_tb);
	}
}

void main() {
	//open 
	FILE* pf = fopen("D:/C-HW/DanhSachHocSinh1.csv", "r");
	if (pf==NULL) {
		printf("Mo file that bai\n");
		return;
	}
	//read
	HocSinh hs[5];
	int n = 0;
	char buffer[1024];

	while (fgets(buffer, sizeof(buffer), pf) != NULL) {
		int result = sscanf(buffer, "%49[^,],%d,%3[^,],%f,%f",
			hs[n].ten,
			&hs[n].tuoi,
			hs[n].gioitinh,
			&hs[n].diem_van,
			&hs[n].diem_toan);

		if (result == 5) {
			hs[n].diem_tb = tinh_diem_tb(hs[n].diem_van, hs[n].diem_toan);
			n++;
		}
		else {
			printf("Error: %s", buffer);
		}
	}
	in_hsmax(hs, n);
	sap_xep_hoc_sinh_cao_thap(hs, n);
	//close
	fclose(pf);

	//open
	FILE* pf1 = fopen("D:/C-HW/DanhSachHocSinh2.csv", "w");
	if (pf1 == NULL) {
		printf("Mo file that bai\n");
		return;
	}
	//write
	for (int i = 0; i < n; i++) {
		fprintf(pf1, "%s,%d,%s,%.2f,%.2f,%.2f\n", hs[i].ten, hs[i].tuoi, hs[i].gioitinh, hs[i].diem_van, hs[i].diem_toan, hs[i].diem_tb);
	}
	//close
	fclose(pf1);
}
