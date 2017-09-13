#include "LinkedList.h"

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

void printList(PLINKEDLIST list){
    PNODE cur;
    for (cur = list->first; cur != NULL; cur = cur->next) {
        printTag(cur->tag);
        printf(" -->\n");
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

void removeList(PLINKEDLIST list){
    PNODE cur = list->first, toDelete;
    while(cur != NULL){
        toDelete = cur;
        cur = cur->next;
        free(toDelete);
    }
    free(cur);
    free(list);
}




