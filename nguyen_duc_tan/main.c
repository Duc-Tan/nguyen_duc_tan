#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

typedef union {
	int size_file;
	char size_bytes[4];
}size_union;

typedef union {
    int sample_rate;
    char rate_bytes[4];
}rate_union;

void main() {
    FILE* pf = fopen("D:/C-HW/audio.wav", "r");
    if (pf == NULL) {
        printf("Mo file that bai\n");
        return 1;
    }
    printf("Mo file thanh cong\n");

    size_union size;
    fseek(pf, 4, SEEK_SET);
    fread(size.size_bytes, sizeof(char), 4, pf);
    int SizeFile = size.size_file;
    printf("Kich thuoc  file : %u byte\n", SizeFile + 8);

	rate_union rate;
    fseek(pf, 24, SEEK_SET);
    fread(rate.rate_bytes, sizeof(char), 4, pf);
    int SampleRate = rate.sample_rate;
    printf("Sample Rate: %u Hz\n", SampleRate);


    fclose(pf);
}