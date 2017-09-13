#ifndef LinkedList_h
#define LinkedList_h

#include <stdio.h>
#include <string.h>

#include "utils.h"

typedef enum _bool{false = 0, true = 1} bool;

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
Remove all of the list
Params:
    1) list - list to remove
*/
void removeList(PLINKEDLIST list);




#endif
