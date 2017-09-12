#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long long ULLONG, *PULLONG;

/*
Gets the file size of a given file pointer
Params:
	1) file - file pointer to the file in ROM
Return:
	return an unsigned long long with the file size in bytes
 */
ULLONG fileSize(FILE* file);

/*
Loads a file from the ROM to the RAM
Params:
	1) filename - file to be loaded in to RAM
	2) size - pointer to where to store the size of the file
Return:
	returns a pointer to the allocated file in ram
 */
char* loadFileToRAM(char* filename, PULLONG size);

/*
Makes a new string from a given one
Params:
	1) src - the src string to copy data from
	2) size - the number of chars to be copied to final string. (Not including \0)
Return:
	A new string from the src string ended with a \0
*/
char* makeStrFrom(char* src, int size);
