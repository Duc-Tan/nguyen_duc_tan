#include<stdio.h>
#include<stdlib.h>

class mang {
public:
	int* data;
	int size;
	mang(int num_item);
	int& operator[](int index);
	void tang_arr(int n);
	void giam_arr(int n);
	~mang();
};

mang::mang(int num_item) {
	data = (int*)malloc(num_item * sizeof(int));
	size = num_item;
}

int& mang::operator[](int index) {
	return data[index];
}

mang::~mang() {
	data = 0;
	free(data);
}

int tong(mang a) {
	int sum = 0;
	for (int i = 0; i < a.size; i++) {
		sum += a[i];
	}
	return sum;
}

void mang::tang_arr(int n) {
	int* new_data = (int*)malloc((size + n) * sizeof(int));
	for (int i = 0; i < size + n; i++) {
		if (i < size)
			new_data[i] = data[i];
		else
			new_data[i] = 0;
	}
	if(data)
	{ 
		
		free(data);
		data = 0;
	}
	data = new_data;
	size += n;
}

void mang::giam_arr(int n) {
	if (n >= size)
	{
		printf("Khong du so phan tu de xoa\n");
		return;
	}
	int* new_data = (int*)malloc((size - n) * sizeof(int));
	for (int i = 0; i < size - n; i++) {
		new_data[i] = data[i];
	}
	if (data)
	{
		free(data);
		data = 0;
	}
	data = new_data;
	size -= n;
}

void main() {
	mang arr(3);
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;

	mang arr2(4);
	arr2[0] = 6;
	arr2[1] = 7;
	arr2[2] = 8;
	arr2[3] = 9;

	int sum = tong(arr);
	arr.tang_arr(2);
	arr2.giam_arr(2);
}