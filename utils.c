#include "utils.h"

ULLONG fileSize(FILE* file) {
	unsigned long long size;
	fseek(file, 0, SEEK_END);
	size = ftell(file);
	fseek(file, 0, SEEK_SET);
	return size;
}

char* loadFileToRAM(char* filename, PULLONG size) {
	FILE* fp;
	char* buffer;
	fp = fopen(filename, "r");
	*size = fileSize(fp);
	buffer = (char*)malloc(*size+1);
	memset(buffer, 0, *size + 1);
	fread(buffer, 1, *size, fp);
	return buffer;
}

char* makeStrFrom(char* src, int size) {
	char* toRet = (char*) malloc(size + 1);
	memset(toRet, 0, size+1);
	strncpy(toRet, src, size);
	return toRet;
}