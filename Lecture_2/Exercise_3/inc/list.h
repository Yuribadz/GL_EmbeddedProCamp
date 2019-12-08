#ifndef LIST_H
#define LIST_H

/**
 * Structure that is used to held data and pointer to the next element.
 */
typedef struct node
{
	int data;
	struct node *next;

} node_t;

/**
 * Function inserts new element to the end of the given linked list.
 * @param list Pointer to the linked list.
 * @param data Integer number to be strored in the given linked list
 * @return char -1 in case of error, 1 in case successfull addition.
 */
char ListAdd(node_t *list, int data);

/**
 * Function checks if the given pointer to node_t element is element of
 * the given linked list.
 * @param list Pointer to the linked list.
 * @param elem Element to be found in the given linked list.
 * @return char Returns -1 in case not found, 1 on found.
 */
char ListIs(node_t *list, node_t *elem);

/**
 * Function removes given element if found in the linked list
 * @param list Pointer to the linked list.
 * @param elem Element to be found in the given linked list.
 * @return char Returns 1 in case of deletion, -1 no element in list.
 */
char ListRemove(node_t *list, node_t *elem);

#endif
