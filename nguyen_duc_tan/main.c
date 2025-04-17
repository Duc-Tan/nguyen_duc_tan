#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<math.h>

typedef float (*func_ptr)(float);

float fx(float x) {
	return x * x;
}

float gx(float x) {
	return 2 * x * x + 3 * x + 1;
}

float tx(float x) {
	return sin(x) + 1;
}

float tinh_tich_phan(int a, int b, func_ptr pfunc) {
	float h = (b - a) / 1000.0f;
	float s = 0;
	for (int i = 0; i < 1000; i++) {
		float db = pfunc(a + i * h);
		float dl = pfunc(a + (i + 1) * h);
		s += (db + dl) * h / 2;
	}
	return s;
}

typedef void (*pfunc)();
pfunc arr_func[] = {fx,gx,tx};

void main() {
	int n;
	int arr_size = sizeof(arr_func) / sizeof(arr_func[0]);
	printf("Nhap vao n= ");
	scanf("%d", &n);
	arr_func[n]();
	float s = tinh_tich_phan(1,2, arr_func[n]);
}