#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "utils.h"
#include "LinkedList.h"

/*
Parses a html page (from RAM) in to a tag linked list
Params:
	1) html - pointer to html page in RAM
Return:
	returns a linked list of all opening and enclosing tags of the given doc
*/
PLINKEDLIST tagparse(char* html);

/*
Gets the name of the html/xml tag
Params:
	1) tag - tag defined struct
Return:
	returns a new alloacted name tag for that tag containing only the name
*/
char* getName(TAG tag);

/*
Gets the attribute of a named tag
Params:
    1) tag - tag defiend struct to pull attributes from
    2) attribute - name of the attribute to be pullen
Return:
    return the value of the given tag's attribute
*/
char* getAttribute(TAG tag, char* attribute);

/*
Find all tags matching a name in html parsed form
Params:
    1) parsedHtml - linked list of tags pointing to an html page
    2) name - name of the tags to find
Return html
 linked list of tag containing only the desired tags
*/
PLINKEDLIST findAll(PLINKEDLIST parsedHtml, char* name);


