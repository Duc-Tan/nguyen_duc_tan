#include <iostream>
#include<math.h>
using namespace std;
class phuongtrinhbac2{
private:
	float a;
	float b;
	float c;
public:
	void nhap() {
		cout << "Nhap a: ";
		cin >> a;
		cout << "Nhap b: ";
		cin >> b;
		cout << "Nhap c: ";
		cin >> c;
	}
	void giai_pt_bac_2() {
		float del;
		del = b * b - 4 * a * c;
		if(del < 0)
			printf("Phuong trinh vo nghiem");
		else if (del == 0) {
			float x = -b / (2 * a);
			printf("Phuong trinh co 1 nghiem: x= %f", x);
		}
		else if (del > 0) {
			float x1 = (-b + sqrt(del)) / (2 * a);
			float x2 = (-b - sqrt(del)) / (2 * a);
			printf("Phuong trinh co 2 nghiem: x1= %f, x2= %f", x1, x2);
		}
	}
};
void main() {
	phuongtrinhbac2 fx;
	fx.nhap();
	fx.giai_pt_bac_2();
}