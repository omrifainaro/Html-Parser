#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utils.h"

typedef enum { false = 0, true = 1 } bool;

typedef struct _TAG {
	bool isStartTag;
	char* startTag;
	char* endTag;
} TAG, *PTAG;

typedef struct _NODE {
	TAG tag;
	struct _NODE* next;
	struct _NODE* prev;
} NODE, *PNODE;

typedef struct _LINKEDLIST {
	PNODE first;
	PNODE last;
} LINKEDLIST, *PLINKEDLIST;

/*
Makes a new node, that describes a tag in html/xml
Params:
	1) isStartTag - defines if it is a starting or enclosing tag
	2) startTag - pointer to the begging of the tag ie '<'
	3) endTag - pointer to the end of the tag ie '>'
Return:	
	Returns a new allocated node containing a tag struct representing that tag
 */
PNODE newNode(bool isStartTag, char* startTag, char* endTag);

/*
Makes a new list
Return:
	returns a new empty list
 */
PLINKEDLIST newList();

/*
Print a tag from '<' to '>'
Parmas:
	1) tag - tag struct to be printed
*/
void printTag(TAG tag);

/*
Prints a new list
Params:
	1) list - a linked list to be printed
*/
void printList(PLINKEDLIST list);

/*
Appends a given node to a given list
Parmas:
	1) list - a linked list to append a given node to
	2) ndoe - the node to appended to the linked list
*/
void appendList(PLINKEDLIST list, PNODE node);

/*
Parses a html page (from RAM) in to a tag linked list
Params:
	1) html - pointer to html page in RAM
Return:
	returns a linked list of all opening and enclosing tags of the given doc
*/
PLINKEDLIST tagparse(char* html);

/*
gets the name of the html/xml tag
Param:
	1) tag - tag defined struct
Return:
	returns a new alloacted name tag for that tag containing only the name
*/
char* getName(TAG tag);