#include "parser.h"

void printTag(TAG tag){
	int size = (tag.endTag - tag.startTag);
	int i;
	for (i = 0; i < size+1; i++) {
		printf("%c", tag.startTag[i]);
	}
}

PLINKEDLIST tagparse(char* html){
    PLINKEDLIST list = newList();
	PNODE node;
	int i = 0;

	//TAG temps
    int isStartTag;
    char *startTag, *endTag;
    
	for (i = 0; i < strlen(html); i++) {
		if (html[i] == '<') {
			startTag = &html[i];
			if (html[i + 1] == '/') {
				isStartTag = 1;
			}
			while (1) {
				if (html[i] != '>') {
					i++;
					continue;
				}
				endTag = &html[i];
				break;
			}
			node = newNode(isStartTag, startTag, endTag);
			appendList(list, node);
		}
	}
    
    return list;
}

int hasAttributes(TAG tag) {
	char beforeClose = *(tag.endTag - 1);
	if (beforeClose == '"' || beforeClose == ' ' || *(tag.startTag+1) == '/') {
		return 1;
	}
	return 0;
}

char* getName(TAG tag) {
	char* name;
	int i = 0;
	char* start = tag.startTag+1;
    if(*start == '/'){
        start++;
    }
	int size;

	while ((start[i] >= 'a' && start[i] <= 'z') || (start[i] >= 'A' && start[i] <= 'Z')) { i++; }
	size = (int)(&start[i] - start);
	return makeStrFrom(start, size);
}

char* getAttribute(TAG tag, char* attribute) {
	char* attributePtr;
	attributePtr = strstr(tag.startTag, attribute);
	int size;
	int i = 0;
    if (attributePtr == NULL || !hasAttributes(tag)) {
		return NULL;
	}
	attributePtr += strlen(attribute) + 2; // 2 -> ="
	while (attributePtr[i] != '"') { i++; }
	size = (int)(&attributePtr[i] - attributePtr);
	return makeStrFrom(attributePtr, size);
}

PLINKEDLIST findAll(PLINKEDLIST parsedHtml, char* name){
    PLINKEDLIST list;
    PNODE cur;
    char* nameTemp;
    
    list = newList();
    for(cur = parsedHtml->first; cur != NULL; cur = cur->next){
        nameTemp = getName(cur->tag);
        if(!strcmp(nameTemp, name)){
            appendList(list, newNode(cur->tag.isStartTag, cur->tag.startTag, cur->tag.endTag));
        }
        free(nameTemp);
    }
    return list;
}










