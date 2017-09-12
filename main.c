#include <stdio.h>
#include "utils.h"
#include "parser.h"

int main(int argc, char* argv[]){
	char* fileData;
	ULLONG fileSize;

	if (argc != 2) {
		printf("Usage: %s <htmlfile>");
		return -1;
	}

	fileData = loadFileToRAM(argv[1], &fileSize);
	printf("pageTitle: %s\n", getTitle(fileData));
	return 1;
}