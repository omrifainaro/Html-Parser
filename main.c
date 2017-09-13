#include <stdio.h>
#include "utils.h"
#include "parser.h"

int main(int argc, char* argv[]){
	char* fileData;
	ULLONG fileSize;

	if (argc < 2) {
		printf("Usage: %s <htmlfile>\n", argv[0]);
		return -1;
	}

	fileData = loadFileToRAM(argv[1], &fileSize);
	PLINKEDLIST list = tagparse(fileData);
	printList(list);
	printf("%s\n", getAttribute(list->first->next->tag, "id"));
	return 1;
}
