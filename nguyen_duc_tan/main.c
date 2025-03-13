#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

void main() {
	int so_tien_can_rut=0;
	int so_to_50=0;
	int so_to_100=0;
	int so_to_200=0;
	int so_to_500=0;
	int so_tien_atm_tra = 0;
	printf("Nhap so tien can rut: ");
	scanf("%d", &so_tien_can_rut);
	if (so_tien_can_rut % 50 != 0) {
		printf("So tien can rut khong hop le");
	}
	else {
		while (so_tien_can_rut > so_tien_atm_tra) {
			if (so_tien_can_rut - so_tien_atm_tra >= 50)
				so_to_50++;
			so_tien_atm_tra = so_to_50 * 50 + so_to_100 * 100 + so_to_200 * 200 + so_to_500 * 500;
			if (so_tien_can_rut - so_tien_atm_tra >= 100)
				so_to_100++;
			so_tien_atm_tra = so_to_50 * 50 + so_to_100 * 100 + so_to_200 * 200 + so_to_500 * 500;
			if (so_tien_can_rut - so_tien_atm_tra >= 200)
				so_to_200++;
			so_tien_atm_tra = so_to_50 * 50 + so_to_100 * 100 + so_to_200 * 200 + so_to_500 * 500;
			if (so_tien_can_rut - so_tien_atm_tra >= 500)
				so_to_500++;
			so_tien_atm_tra = so_to_50 * 50 + so_to_100 * 100 + so_to_200 * 200 + so_to_500 * 500;
		}
		printf("So to 50: %d\n", so_to_50);
		printf("So to 100: %d\n", so_to_100);
		printf("So to 200: %d\n", so_to_200);
		printf("So to 500: %d\n", so_to_500);
		printf("So tien ATM tra: %d\n", so_tien_atm_tra);
	}
}