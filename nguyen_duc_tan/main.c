#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

// Chuc nang: Xay dung ham mo ta doi tuong phan so
typedef struct {
	int tu;
	int mau;
} Phanso;

//Chuc nang: chia 2 phan so
//Input: 2 phan so a, b
//Output: Ket qua cua phep chia a/b
Phanso chia(Phanso a, Phanso b) {
	Phanso kq;
	kq.tu = a.tu * b.mau;
	kq.mau = a.mau * b.tu;
	return kq;
}

//Chuc nang: cong 2 phan so
//Input: 2 phan so a, b
//Output: Ket qua cua phep cong a+b
Phanso cong(Phanso a, Phanso b) {
	Phanso kq;
	kq.tu = a.tu * b.mau + b.tu * a.mau;
	kq.mau = a.mau * b.mau;
	return kq;
}

// Chuc nang: tru 2 phan so
// Input: 2 phan so a, b
// Output: Ket qua cua phep tru a-b
Phanso tru(Phanso a, Phanso b) {
	Phanso kq;
	kq.tu = a.tu * b.mau - b.tu * a.mau;
	kq.mau = a.mau * b.mau;
	return kq;
}

// Chuc nang: rut gon phan so
// Input: 1 phan so
// Output: Phan so sau khi rut gon
Phanso rutgon(Phanso a) {
	Phanso kq;
	int ucln = 1;
	for (int i = 1; i <= a.tu && i <= a.mau; i++) {
		if (a.tu % i == 0 && a.mau % i == 0) {
			ucln = i;
		}
	}
	kq.tu = a.tu / ucln;
	kq.mau = a.mau / ucln;
	return kq;
}

void main() {
	Phanso a = { 1, 2 };
	Phanso b = { 6, 36 };

	Phanso c = chia(a, b);
	printf("%d/%d", c.tu, c.mau);

	Phanso d = cong(a, b);
	printf("\n%d/%d", d.tu, d.mau);

	Phanso e = tru(a, b);
	printf("\n%d/%d", e.tu, e.mau);

	Phanso f = rutgon(d);
	printf("\n%d/%d", f.tu, f.mau);
}