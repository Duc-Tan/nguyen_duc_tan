#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	char light;
	char fan;
	char motor;
}smartHome_t;

const char* data = "HTTP1.1 200 OK{"\
"\"light\": \"on\","\
"\"fan\" : \"off\","\
"\"motor\" : \"off\"}";

smartHome_t pair_data(const char* data) {
	smartHome_t x;
	//light
	char* light = "\"light\": \"";
	char* pl = strstr(data, light);
	pl += strlen(light);
	int i = 0;
	while (pl[i] != '\"') {
		i++;
	}
	char* light_state = malloc(i + 1);
	memset(light_state, 0, i + 1);
	memcpy(light_state, pl, i);

	if (strcmp(light_state, "on") == 0) {
		free(light_state);
		x.light = 1;
	}
	else if (strcmp(light_state, "off") == 0) {
		free(light_state);
		x.light = 0;
	}
	//fan
	char* fan = "\"fan\" : \"";
	char* pf = strstr(data, fan);
	pf += strlen(fan);
	int j = 0;
	while (pf[j] != '\"') {
		j++;
	}
	char* fan_state = malloc(j + 1);
	memset(fan_state, 0, j + 1);
	memcpy(fan_state, pf, j);

	if (strcmp(fan_state, "on") == 0) {
		free(fan_state);
		x.fan = 1;
	}
	else if (strcmp(fan_state, "off") == 0) {
		free(fan_state);
		x.fan = 0;
	}
	//motor
	char* motor = "\"motor\" : \"";
	char* pm = strstr(data, motor);
	pm += strlen(motor);
	int z = 0;
	while (pm[z] != '\"') {
		z++;
	}
	char* motor_state = malloc(z + 1);
	memset(motor_state, 0, z + 1);
	memcpy(motor_state, pm, z);

	if (strcmp(motor_state, "on") == 0) {
		free(motor_state);
		x.motor = 1;
	}
	else if (strcmp(motor_state, "off") == 0) {
		free(motor_state);
		x.motor = 0;
	}
	return x;
}

int main()
{
	smartHome_t x = pair_data(data);
	int light = x.light;
	int fan = x.fan;
	int motor = x.motor;

	return 0;
}