/* CS261- Assignment 3, part 1 */
/* Name: Patrick Mullaney
 * Date: 1/13/17
 * Solution description:  Implementation file for linked List used for performance testing.
 */

#include "linkedList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

// Double link
struct Link
{
	TYPE value;
	struct Link* next;
	struct Link* prev;
};

// Double linked list with front and back sentinels
struct LinkedList
{
	int size;
	struct Link* frontSentinel;
	struct Link* backSentinel;
};

/**
 * Allocates the list's sentinel and sets the size to 0.
 * The sentinels' next and prev should point to eachother or NULL
 * as appropriate.
 */
static void init(struct LinkedList* list) {
	// FIXME: you must write this
    list->frontSentinel = malloc(sizeof(struct Link));
    list->backSentinel = malloc(sizeof(struct Link));
    
    list->frontSentinel->next = list->backSentinel;
    list->frontSentinel->prev = list->backSentinel;
    list->backSentinel->next = list->frontSentinel;
    list->backSentinel->prev = list->frontSentinel;
    list->size = 0;
}

/**
 * Adds a new link with the given value before the given link and
 * increments the list's size.
 */
static void addLinkBefore(struct LinkedList* list, struct Link* link, TYPE value)
{
	// FIXME: you must write this
    /* Assert list is not null and allocate memry for newLink */
    assert(list);
    struct Link* newLink = (struct Link*)malloc(sizeof(struct Link));
    assert(newLink);
    /* After newLink created, set value, insert into linked list by updating pointers*/
    newLink->value = value;
    newLink->next = link;
    newLink->prev = link->prev;
    link->prev = newLink;
    list->size++; /* Increment size */
}

/**
 * Removes the given link from the list and
 * decrements the list's size.
 */
static void removeLink(struct LinkedList* list, struct Link* link)
{
	// FIXME: you must write this
    assert(list);
    /* Update pointers to remove from list */
    link->prev->next = link->next;
    link->next->prev = link->prev;
    /* Free memory allocated to link */
    free(link);
    list->size--; /* Decrement size */
}

/**
 * Allocates and initializes a list.
 */
struct LinkedList* linkedListCreate()
{
	struct LinkedList* newDeque = malloc(sizeof(struct LinkedList));
	init(newDeque);
	return newDeque;
}

/**
 * Deallocates every link in the list including the sentinels,
 * and frees the list itself.
 */
void linkedListDestroy(struct LinkedList* list)
{
	while (!linkedListIsEmpty(list))
	{
		linkedListRemoveFront(list);
	}
	free(list->frontSentinel);
	free(list->backSentinel);
	free(list);
}

/**
 * Adds a new link with the given value to the front of the deque.
 */
void linkedListAddFront(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this
  
    /* Try 1 worked, attempted with addLinkBefore as well.
    assert(list);
    struct Link* newLink = (struct Link*)malloc(sizeof(struct Link));
    assert(newLink);
    
    newLink->value = value;
    newLink->prev = list->frontSentinel;
    newLink->next = list->frontSentinel->next;
    newLink->next->prev = newLink;
    list->frontSentinel->next = newLink;
    list->size++; */
    
    /* Try 2 using addLinkBefore */
    addLinkBefore(list, list->frontSentinel->next, value);
}

/**
 * Adds a new link with the given value to the back of the deque.
 */
void linkedListAddBack(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this
    /* Assert list is not null and allocate memory for new link */
    assert(list);
    struct Link* newLink = (struct Link*)malloc(sizeof(struct Link));
    assert(newLink);
    /* After newLink allocated, set value and update pointers */
    newLink->value = value;
    newLink->prev = list->backSentinel->prev;
    newLink->next = list->backSentinel;
    newLink->prev->next = newLink;
    list->backSentinel->prev = newLink;
    list->size++; /* Increment size */
}

/**
 * Returns the value of the link at the front of the deque.
 */
TYPE linkedListFront(struct LinkedList* list)
{
	// FIXME: you must write this
    /* Assert list isn't empty */
    assert(list->frontSentinel->next != list->backSentinel);
    return list->frontSentinel->next->value;
}

/**
 * Returns the value of the link at the back of the deque.
 */
TYPE linkedListBack(struct LinkedList* list)
{
	// FIXME: you must write this
    /* Assert list isn't empty */
    assert(list->backSentinel->prev != list->frontSentinel);
    return list->backSentinel->prev->value;
}

/**
 * Removes the link at the front of the deque.
 */
void linkedListRemoveFront(struct LinkedList* list)
{
	// FIXME: you must write this
   /* Try 1 worked, attempted second try utilizing removeLink.
    assert(list);
    assert(list->frontSentinel->next != list->backSentinel);
    list->frontSentinel->next = list->frontSentinel->next->next;
    free(list->frontSentinel->next->prev);
    list->frontSentinel->next->prev = list->frontSentinel;
    list->size--; */
    
    /* Try 2, using removeLink */
    removeLink(list, list->frontSentinel->next);
}

/**
 * Removes the link at the back of the deque.
 */
void linkedListRemoveBack(struct LinkedList* list)
{
	// FIXME: you must write this
    /* Try 1 worked, attempted second try utilizing removeLink.
     
    assert(list->backSentinel->prev != list->frontSentinel);
    list->backSentinel->prev = list->backSentinel->prev->prev;
    free(list->backSentinel->prev->next);
    list->backSentinel->prev->next = list->backSentinel;
    list->size--; */
    
    /* Try 2 with removeLink, also worked.*/
    removeLink(list, list->backSentinel->prev);
}

/**
 * Returns 1 if the deque is empty and 0 otherwise.
 */
int linkedListIsEmpty(struct LinkedList* list)
{
	// FIXME: you must write this
    assert(list);
    int empty;
    empty = 0;
    
    if((list->frontSentinel->next==list->backSentinel)&&(list->backSentinel->prev == list->frontSentinel))
        empty = 1;
    return empty;
}

/**
 * Prints the values of the links in the deque from front to back.
 */
void linkedListPrint(struct LinkedList* list)
{
	// FIXME: you must write this
    assert(list->frontSentinel->next != list->backSentinel);
    int value;
    
    struct Link* temp = list->frontSentinel->next;
    
    while(temp!= list->backSentinel)
    {
        value = temp->value;
        printf(" %d ", value);
        temp = temp->next;
    }
}

/**
 * Adds a link with the given value to the bag.                     *** check this
 */
void linkedListAdd(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this
    struct Link* newLink = (struct Link*)malloc(sizeof(struct Link));
    assert(newLink);
    newLink->value = value;
    newLink->next = list->frontSentinel->next;
    list->frontSentinel->next = newLink;
    newLink->next->prev = newLink;
    newLink->prev = list->frontSentinel;
    list->size++;
}

/**
 * Returns 1 if a link with the value is in the bag and 0 otherwise.
 */
int linkedListContains(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this
    assert(list->frontSentinel->next != list->backSentinel);
    struct Link* temp;
    temp = list->frontSentinel->next;
    int match;
    match = 0;
    while((temp->next!= list->backSentinel) && (match == 0))
    {
        if(temp->value == value)
        {
            match = 1;
        }
        temp = temp->next;
    }
    return match;
}

/**
 * Removes the first occurrence of a link with the given value.
 */
void linkedListRemove(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this
    assert(list->frontSentinel->next != list->backSentinel);
    assert(linkedListContains(list, value));
    struct Link* temp;
    temp = list->frontSentinel->next;
    int match;
    match = 0;
    while((temp->next != list->backSentinel) && (match == 0))
    {
        if(temp->value == value)
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            free(temp);
            match = 0;
        }
        temp = temp->next;
    }
}
