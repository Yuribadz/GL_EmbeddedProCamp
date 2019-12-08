#include <stdio.h>
#include <stdlib.h>
#include "list.h"

char ListAdd(node_t *list, int data)
{
	node_t *pos = list;
	while (pos->next != NULL){
		pos = pos->next;
	}
	pos->next = malloc(sizeof(node_t));
	if (pos->next == NULL){
		return -1;
	}
	pos->next->data = data;
	pos->next->next = NULL;
	return 1;
}

char ListIs(node_t *list, node_t *elem)
{
	char is = 0;
	node_t *pos = list;

	while (pos != NULL){
		if (pos == elem)
		{
			is = 1;
			break;
		}
		pos = pos->next;
	}
	return is;
}

char ListRemove(node_t *list, node_t *elem)
{
	node_t *pos = list;

	while (pos != NULL)
	{
		if (pos->next == elem){

			pos->next = elem->next;
			free(elem);
			return 1;
		}
		pos = pos->next;
	}
	return -1;
}

int main(void)
{
	node_t *testList = NULL;
	testList = malloc(sizeof(node_t));

	if (testList == NULL){
		printf("Could not allocate memory for list\n");
		return -1;
	}

        testList->data = 0;
	testList->next = NULL;

	node_t *testElem = NULL;
	testElem = malloc(sizeof(node_t));

	if (testElem == NULL){
		printf("Could not allocate memory for test element\n");
		return -1;
	}

        testElem->data = 1;
	testElem->next = NULL;

	if(ListAdd(testList, 1) &&
		ListAdd(testList, 2) &&
		ListAdd(testList, 3))
	{
		node_t* testIter = testList;
		printf("List now contains : ");
		while(testIter != NULL)
		{
			printf("%d ", testIter->data);
			testIter = testIter->next;
		}
		printf("\n");
	}

	if(ListIs(testList, testElem))
	{
		printf("Test element was found in list\n");
	}
	else
	{
		printf("Test element was not found in list\n");
	}

	// Remove first element from list
	if(ListRemove(testList, testList->next))
	{
		printf("Successfully deleted first element from list\n");
	}
}
