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
Param:
	1) tag - tag defined struct
Return:
	returns a new alloacted name tag for that tag containing only the name
*/
char* getName(TAG tag);

/*
Gets the attribute of a named tag
Param:
    1) tag - tag defiend struct to pull attributes from
    2) attribute - name of the attribute to be pullen
Return:
    return the value of the given tag's attribute
*/
char* getAttribute(TAG tag, char* attribute);
