#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long long ULLONG, *PULLONG;

/*
 * Returns the file size of a given file pointer
 */
ULLONG fileSize(FILE* file);

/*
 * Loads a file from the ROM to the RAM
 * Params:
 *	1) filename - file to be loaded in to RAM
 *  2) size - pointer to where to store the size of the file
 * Return:
 *	returns a pointer to the allocated file in ram
 */
char* loadFileToRAM(char* filename, PULLONG size);
