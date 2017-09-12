#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum { false, true } bool;

typedef struct _TAG{
    bool isStartTag;
    char* startTag;
    char* endTag;
} TAG, *PTAG;

typedef struct _NODE{
    TAG tag;
    struct _NODE* next;
    struct _NODE* prev;
} NODE, *PNODE;

typedef struct _LINKEDLIST{
    PNODE first;
    PNODE last;
} LINKEDLIST, *PLINKEDLIST;

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
    PNODE cur = list->first;
    while(cur != NULL){
        printf("%s --> ", cur->tag.startTag);
        cur = cur->next;
    }
    printf("NULL");
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
    char* token = strtok(html, "<");
    
    //TAG temps
    bool isStartTag;
    char *startTag, *endTag;
    
    while(token != NULL){
        isStartTag = !(*(token+1) == '/');
        startTag = token;
        token = strtok(NULL, ">");
        endTag = token;
        appendList(list, newNode(isStartTag, startTag, endTag));
        token = strtok(NULL, "<");
    }
    
    return list;
}

int main(int argc, char* argv[]){
    char htmlPage[92] = "<html><head><title>tasikef</title></head><body><a href='tasik.com'>poopik</a></body></html>\0";
    PLINKEDLIST list = tagparse(htmlPage);
    printList(list);
    return 0;
}
