#include "parser.h"

PNODE newNode(bool isStartTag, char* startTag, char* endTag){
    PNODE node = (PNODE) malloc(sizeof(NODE));
    node->tag.startTag = startTag;
    node->tag.isStartTag = isStartTag;
    node->tag.endTag = endTag;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

PLINKEDLIST newList(){
    PLINKEDLIST list = (PLINKEDLIST) malloc(sizeof(LINKEDLIST));
    list->first = NULL;
    list->last = NULL;
    return list;
}

void printTag(TAG tag){
	int size = (tag.endTag - tag.startTag);
	int i;
	for (i = 0; i < size+1; i++) {
		printf("%c", tag.startTag[i]);
	}
}

void printList(PLINKEDLIST list){
	PNODE cur;
	for (cur = list->first; cur != NULL; cur = cur->next) {
		printTag(cur->tag);
		printf(" --> ");
	}
    printf("NULL\n");
}

void appendList(PLINKEDLIST list, PNODE node){
    if(list->first == NULL){
        list->first = node;
        list->last = node;
    }
    else{
        list->last->next = node;
        node->prev = list->last;
        list->last = list->last->next;
    }
}

PLINKEDLIST tagparse(char* html){
    PLINKEDLIST list = newList();
	PNODE node;
	int i = 0;

	//TAG temps
    bool isStartTag;
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

bool hasAttributes(TAG tag) {
	char beforeClose = *(tag.endTag - 1);
	if (beforeClose == '"' || beforeClose == ' ') {
		return true;
	}
	return false;
}

char* getName(TAG tag) {
	char* name;
	int i = 0;
	char* start = tag.startTag+1;
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
	if (attributePtr == NULL) {
		return NULL;
	}
	attributePtr += strlen(attribute) + 2; // 2 -> ="
	while (attributePtr[i] != '"') { i++; }
	size = (int)(&attributePtr[i] - attributePtr);
	return makeStrFrom(attributePtr, size);
}