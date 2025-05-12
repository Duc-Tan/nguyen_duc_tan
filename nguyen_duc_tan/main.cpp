#include <stdio.h>
class phan_so {
public:
	int tu;
	int mau;
	phan_so nhan(phan_so khac);
	phan_so chia(phan_so khac);
	phan_so cong(phan_so khac);
	phan_so tru(phan_so khac);
	phan_so rut_gon();
	void ss_lon_hon(phan_so khac);
	void ss_be_hon(phan_so khac);
	void ss_lon_hon_bang(phan_so khac);
	void ss_be_hon_bang(phan_so khac);
	void ss_bang(phan_so khac);
	phan_so(int t, int m);
	phan_so();
};

phan_so::phan_so(int t, int m) {
	tu = t;
	mau = m;
}

phan_so::phan_so() {
	tu = 0;
	mau = 0;
}

phan_so phan_so::nhan(phan_so khac) {
	phan_so kq;
	kq.tu = tu * khac.tu;
	kq.mau = mau * khac.mau;
	return kq;
}

phan_so phan_so::chia(phan_so khac) {
	phan_so kq;
	kq.tu = tu * khac.mau;
	kq.mau = mau * khac.tu;
	return kq;
}

phan_so phan_so::cong(phan_so khac) {
	phan_so kq;
	kq.tu = tu * khac.mau + mau * khac.tu;
	kq.mau = mau * khac.mau;
	return kq;
}

phan_so phan_so::tru(phan_so khac) {
	phan_so kq;
	kq.tu = tu * khac.mau - mau * khac.tu;
	kq.mau = mau * khac.mau;
	return kq;
}

phan_so phan_so::rut_gon() {
	phan_so kq;
	int ucln = 1;
	for (int i = 1; i <= tu && i <= mau; i++) {
		if (tu % i == 0 && mau % i == 0) {
			ucln = i;
		}
	}
	kq.tu = tu / ucln;
	kq.mau = mau / ucln;
	return kq;
}

void phan_so::ss_lon_hon(phan_so khac) {
	if (tu / (float)mau > khac.tu / (float)khac.mau) {
		printf("%d/%d lon hon %d/%d\n", tu, mau, khac.tu, khac.mau);
	}
	else {
		printf("%d/%d KHONG lon hon %d/%d\n", tu, mau, khac.tu, khac.mau);
	}
}

void phan_so::ss_be_hon(phan_so khac) {
	if (tu / (float)mau < khac.tu / (float)khac.mau) {
		printf("%d/%d be hon %d/%d\n", tu, mau, khac.tu, khac.mau);
	}
	else {
		printf("%d/%d KHONG be hon %d/%d\n", tu, mau, khac.tu, khac.mau);
	}
}

void phan_so::ss_lon_hon_bang(phan_so khac) {
	if (tu / (float)mau >= khac.tu / (float)khac.mau) {
		printf("%d/%d lon hon bang %d/%d\n", tu, mau, khac.tu, khac.mau);
	}
	else {
		printf("%d/%d KHONG lon hon bang %d/%d\n", tu, mau, khac.tu, khac.mau);
	}
}

void phan_so::ss_be_hon_bang(phan_so khac) {
	if (tu / (float)mau <= khac.tu / (float)khac.mau) {
		printf("%d/%d be hon bang %d/%d\n", tu, mau, khac.tu, khac.mau);
	}
	else {
		printf("%d/%d KHONG be hon bang %d/%d\n", tu, mau, khac.tu, khac.mau);
	}
}

void phan_so::ss_bang(phan_so khac) {
	if (tu / (float)mau == khac.tu / (float)khac.mau) {
		printf("%d/%d bang %d/%d\n", tu, mau, khac.tu, khac.mau);
	}
	else {
		printf("%d/%d KHONG bang %d/%d\n", tu, mau, khac.tu, khac.mau);
	}
}

void main() {
	phan_so a(2, 3);
	phan_so b(3, 4);

	phan_so tich;
	tich = a.nhan(b);
	printf("%d/%d * %d/%d = %d/%d\n", a.tu, a.mau, b.tu, b.mau, tich.tu, tich.mau);

	phan_so thuong;
	thuong = a.chia(b);
	printf("%d/%d / %d/%d = %d/%d\n", a.tu, a.mau, b.tu, b.mau, thuong.tu, thuong.mau);

	phan_so tong;
	tong = a.cong(b);
	printf("%d/%d + %d/%d = %d/%d\n", a.tu, a.mau, b.tu, b.mau, tong.tu, tong.mau);

	phan_so hieu;
	hieu = a.tru(b);
	printf("%d/%d - %d/%d = %d/%d\n", a.tu, a.mau, b.tu, b.mau, hieu.tu, hieu.mau);

	phan_so rutgon;
	rutgon = tich.rut_gon();
	printf("Rut gon: %d/%d = %d/%d\n", tich.tu, tich.mau, rutgon.tu, rutgon.mau);

	a.ss_lon_hon(b);
	a.ss_be_hon(b);
	a.ss_lon_hon_bang(b);
	a.ss_be_hon_bang(b);
	a.ss_bang(b);

	b.ss_lon_hon(a);
	b.ss_be_hon(a);
	b.ss_lon_hon_bang(a);
	b.ss_be_hon_bang(a);
	b.ss_bang(b);
}