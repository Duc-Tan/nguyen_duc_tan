#include <stdint.h>﻿
#include<stdlib.h>
#include<stdio.h>


typedef struct {
    char ten[50];
    int tuoi;
    char gioitinh[4];
    float diemvan;
    float diemtoan;
    float diemtb;
} HocSinh;

float Tinh_TB(float a, float b) {
    return (a + b) / 2.0f;
}

void main() {
    FILE* pf = fopen("D:/C-HW/DanhSachHocSinh1.csv", "r");

    if (pf == NULL) {
        printf("Mo file that bai \n");
        return 1;
    }

    HocSinh hs[5];
    int n = 0;
    char buffer[1024];


    while (fgets(buffer, sizeof(buffer), pf) != NULL) {
        int result = sscanf(buffer, "%49[^,],%d,%3[^,],%f,%f",
            hs[n].ten,
            &hs[n].tuoi,
            hs[n].gioitinh,
            &hs[n].diemvan,
            &hs[n].diemtoan);

        if (result == 5) {
            hs[n].diemtb = Tinh_TB(hs[n].diemvan, hs[n].diemtoan);
            n++;
        }
        else {
            printf("Error: %s", buffer);
        }
    }
    int index = 0;
    for (int i = 1; i < n; i++) {
        if (hs[i].diemtb > hs[index].diemtb) {
            index = i;
        }
    }

    HocSinh hsmax = hs[index];
    printf("Hoc sinh co diem trung binh cao nhat:\n");
    printf("Ten: %s\n", hsmax.ten);
    printf("Tuoi : %d\n", hsmax.tuoi);
    printf("Gioi tinh: %s\n", hsmax.gioitinh);
    printf("Diem Van: %.2f\n", hsmax.diemvan);
    printf("Diem Toan: %.2f\n", hsmax.diemtoan);
    printf("Diem TB : %.2f\n", hsmax.diemtb);

    HocSinh temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {

            if (hs[i].diemtb < hs[j].diemtb)
            {
                temp = hs[i];
                hs[i] = hs[j];
                hs[j] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%s,%d,%s,%.2f,%.2f,%.2f\n", hs[i].ten, hs[i].tuoi, hs[i].gioitinh,
            hs[i].diemvan, hs[i].diemtoan, hs[i].diemtb);
    }


    FILE* pf_1 = fopen("D:/C-HW/SapXep.txt", "w");

    if (pf_1 == NULL) {
        printf("Error.\n");
        return 1;
    }
    for (int i = 0; i < 5; i++) {
        fprintf(pf_1, "%s,%d,%s,%.2f,%.2f,%.2f\n", hs[i].ten, hs[i].tuoi, hs[i].gioitinh,
            hs[i].diemvan, hs[i].diemtoan, hs[i].diemtb);
    }
    fclose(pf_1);
    fclose(pf);
}