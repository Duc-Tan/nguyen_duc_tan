#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int xu_ly_ham(char* str, char* key) {
	char* p = strstr(str, key);// tim vi tri tu khoa trong chuoi
	p += strlen(key);// di chuyen con tro den vi tri sau tu khoa

	int i = 0;
	while (p[i] != ',') {
		i++;
	}//tim do dai cua tu khoa
	char* key_state = malloc(i + 1);// cap phat bo nho cho chuoi con
	memset(key_state, 0, i + 1);// khoi tao chuoi = 0
	memcpy(key_state, p, i);// sao chep chuoi con tu vi tri p

	if (strcmp(key_state, "on") == 0) {
		free(key_state);
		return 1;
	}
	else if (strcmp(key_state, "off") == 0) {
		free(key_state);
		return 0;
	}
}




void main() {
	char str[] = "light: on, fan: off, motor: off";
	char light[] = "light: ";
	char fan[] = "fan: ";
	char motor[] = "motor: ";

	int (*function)(char* str, char* key);
	function = xu_ly_ham;

	int light_state = xu_ly_ham(str, light);
	int fan_state = xu_ly_ham(str, fan);
	int motor_state = xu_ly_ham(str, motor);
}