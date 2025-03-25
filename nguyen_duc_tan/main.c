#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

struct PhanSo {
	int tu;
	int mau;
};

// Nhan 2 phan so
// Input: 2 phan so A , B
// Output: Phan so C = A * B
struct PhanSo nhan(struct PhanSo A, struct PhanSo B) {
	struct PhanSo C;
	C.tu = A.tu * B.tu;
	C.mau = A.mau * B.mau;
	return C;
};

void main() {
	struct PhanSo A;
	struct PhanSo B;

	A.tu = 3;
	A.mau = 2;

	B.tu = 3;
	B.mau = 5;

	struct PhanSo C = nhan(A, B);
	printf("%d/%d", C.tu, C.mau);
}