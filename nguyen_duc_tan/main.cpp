#include<stdio.h>
#include<iostream>
#include<stdlib.h>

class mang {
public:
    int* data;
    int size;
    mang(int num_item) {
        data = (int*)malloc(num_item * sizeof(int));
        size = num_item;
    }
    int& operator[](int index) {
        return data[index];
    }

    //Chuc nang: them gia tri moi vao cuoi mang
    //Input: int val (gia tri moi)
    //Output: khong co
    void push_back(int val) {
        //Cap phat vung nho moi lon hon
        int* new_data = (int*)malloc((size + 1) * sizeof(int));
        //Sao chep gia tri vung nho cu vao vung nho moi
        for (int i = 0; i < size; i++) {
            new_data[i] = data[i];
        }
        //Them gia tri moi vao mang
        new_data[size] = val;
        //Giai phong vung nho cu
        free(data);
        //Cap nhat dia chi cua vung nho moi vao con tro data
        data = new_data;
        //Cap nhat gia tri cua bien size
        size++;
    }
    //Chuc nang: xoa gia tri cuoi mang
    //Input: khong co
    //Output: khong co
    void pop_back() {
        //Cap phat vung nho moi nho hon
        int* new_data = (int*)malloc((size - 1) * sizeof(int));
        //Sao chep gia tri vung nho cu vao vung nho moi
        for (int i = 0; i < size - 1; i++) {
            new_data[i] = data[i];
        }
        //Giai phong vung nho cu
        free(data);
        //Cap nhat dia chi cua vung nho moi vao con tro data
        data = new_data;
        //Cap nhat gia tri cua bien size
        size--;
    }

    ~mang() {
        free(data);
    }
};


int main(void) {
    mang a(5);
    for (int i = 0; i < 5; i++) {
        a[i] = i + 1;
    }
    a.pop_back();
	a.push_back(6);
	a.push_back(7);

    return 0;
}