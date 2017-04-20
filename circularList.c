/* CS261- Assignment 3, part 3. */
/* Name: Patrick Mullaney
 * Date: 1/13/17
 * Solution description:  Implementation file for circular linked list.
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "circularList.h"

// Double link
struct Link
{
	TYPE value;
	struct Link * next;
	struct Link * prev;
};

struct CircularList
{
	int size;
	struct Link* sentinel;
};

/**
 * Allocates the list's sentinel and sets the size to 0.
 * The sentinel's next and prev should point to the sentinel itself.
 */
static void init(struct CircularList* list)
{
	// FIXME: you must write this
    /* Assert list is valid and allocate list sentinel */
    assert(list);
    list->sentinel = (struct Link*)malloc(sizeof(struct Link));
    assert(list->sentinel);
    /* Initialize pointers and list-size */
    list->sentinel->next = list->sentinel;
    list->sentinel->prev = list->sentinel;
    list->size = 0;
}

/**
 * Creates a link with the given value and NULL next and prev pointers.
 */
static struct Link* createLink(TYPE value)
{
	// FIXME: you must write this
    struct Link* newLink = (struct Link*)malloc(sizeof(struct Link));
    assert(newLink);
    newLink->value = value;
    newLink->next = NULL;
    newLink->prev = NULL;
	return newLink;
}

/**
 * Adds a new link with the given value after the given link and
 * increments the list's size.
 */
static void addLinkAfter(struct CircularList* list, struct Link* link, TYPE value)
{
	// FIXME: you must write this
    assert(list);
    struct Link* newLink = createLink(value);
  
    if(link == list->sentinel) // If front, adjust pointers.
    {
        newLink->next = link->next;
        newLink->prev = link;
        list->sentinel->next = newLink;
        newLink->next->prev = newLink;
    }
    else if(link == list->sentinel->prev) // If back, adjust pointers.
    {
        newLink->next = list->sentinel;
        newLink->prev = link;
        link->next = newLink;
        list->sentinel->prev = newLink;
    }
    list->size++;
}

/**
 * Removes the given link from the list and
 * decrements the list's size.
 */
static void removeLink(struct CircularList* list, struct Link* link)
{
	// FIXME: you must write this
    assert(list); /* Assert list is valid */

    if(link == list->sentinel->next) /* If first link */
    {
        list->sentinel->next = link->next;
        list->sentinel->next->prev = list->sentinel;
    }
    else if(link == list->sentinel->prev) /* Update pointers */
    {
        list->sentinel->prev = link->prev;
        list->sentinel->prev->next = list->sentinel;
    }
  
    link->next->prev = link->prev;
    /* Free link and decrement size */
    free(link);
    list->size--;
}

/**
 * Allocates and initializes a list.
 */
struct CircularList* circularListCreate()
{
	struct CircularList* list = malloc(sizeof(struct CircularList));
	init(list);
	return list;
}

/**
 * Deallocates every link in the list and frees the list pointer.
 */
void circularListDestroy(struct CircularList* list)
{
	// FIXME: you must write this
    /* Assert list is valid */
    assert(list);
    struct Link* temp; /* Point to front of list */
    temp = list->sentinel->next;
    assert(temp!= list->sentinel);
    
    /* Loop through and deallocate links */
    while(temp!= list->sentinel)
    {
        temp = temp->next;
        free(temp->prev);
    }
    /* Then deallocate list sentinel and pointer */
    free(list->sentinel);
    free(list);
}

/**
 * Adds a new link with the given value to the front of the deque.
 */
void circularListAddFront(struct CircularList* list, TYPE value)
{
	// FIXME: you must write this
    /* Assert list is valid */
    assert(list);
    addLinkAfter(list, list->sentinel, value); /* Add to front */
}

/**
 * Adds a new link with the given value to the back of the deque.
 */
void circularListAddBack(struct CircularList* list, TYPE value)
{
	// FIXME: you must write this
    assert(list); /* Assert list is valid */
    
    /** Note: could be done with addLinkAfter, however
     ** was experimenting with different ways to implement */
    
    if(circularListIsEmpty(list)) /* If list is empty, add to the front */
    {
        /* Allocate link and adjust pointers  */
        struct Link* newLink = createLink(value);
        assert(newLink);
        newLink->next = list->sentinel->next;
        newLink->prev = list->sentinel->prev;
        list->sentinel->prev = newLink;
        list->sentinel->next = newLink;
        list->size++;
    }
    else
        addLinkAfter(list, list->sentinel->prev, value); /* Else add after first */
}

/**
 * Returns the value of the link at the front of the deque.
 */
TYPE circularListFront(struct CircularList* list)
{
	// FIXME: you must write this
    /* Assert list is valid and not empty */
    assert(list);
    assert(circularListIsEmpty(list)!=1);
    /* Return value at first link  */
    int front;
    front = list->sentinel->next->value;
	return front;
}

/**
 * Returns the value of the link at the back of the deque.
 */
TYPE circularListBack(struct CircularList* list)
{
	// FIXME: you must write this
    /* Assert list is valid and not empty */
    assert(list);
    assert(circularListIsEmpty(list)!= 1);
    /* Return value at last link */
    int back;
    back = list->sentinel->prev->value;
	return back;
}

/**
 * Removes the link at the front of the deque.
 */
void circularListRemoveFront(struct CircularList* list)
{
	// FIXME: you must write this
    
    /* Assert list is valid and not empty */
    assert(list);
    assert(circularListIsEmpty(list)!= 1);
    /* Remove link at front  */
    removeLink(list, list->sentinel->next);
}

/**
 * Removes the link at the back of the deque.
 */
void circularListRemoveBack(struct CircularList* list)
{
	// FIXME: you must write this
    /** Note: could be done same as circularListRemoveFront, however
    ** was experimenting with different ways to implement */
    
    /* Assert list is valid and not empty */
    assert(list);
    assert(circularListIsEmpty(list)!= 1);
    
    /* store link in temp, adjust pointers */
    struct Link* temp = list->sentinel->prev;
    list->sentinel->prev = temp->prev;
    list->sentinel->prev->next = list->sentinel;
    /* free temp and decrement size */
    free(temp);
    list->size--;
}

/**
 * Returns 1 if the deque is empty and 0 otherwise.
 */
int circularListIsEmpty(struct CircularList* list)
{
	// FIXME: you must write this
    /* Assert list is valid */
    assert(list);
    /* Initialize empty to 0 */
    int empty;
    empty = 0;
    if((list->sentinel->next == list->sentinel)&&(list->sentinel->prev == list->sentinel))
    {
        empty = 1; /* If front and back sentinels point to each other, return 1 */
    }
	return empty;
}

/**
 * Prints the values of the links in the deque from front to back.
 */
void circularListPrint(struct CircularList* list)
{
	// FIXME: you must write this
    /* Assert list is valid and not empty */
    assert(list);
    assert(circularListIsEmpty(list)!=1);
    
    /* Create temp pointer and start at beginning, loop through and print out values */
    struct Link* temp;
    temp = list->sentinel->next;
  
    while(temp!= list->sentinel)
    {
        printf("%f ", temp->value);
        temp = temp->next;
    }
    printf("\n");
    
    /* Used for testing printed values front to back, then back to front
    int i;
    printf(" front to back: ");
    for(i = 0; i < list->size; i++)
    {
        printf(" %f ", temp->value);
        temp = temp->next;
    }
    
    printf("\n back to front: ");
    temp = list->sentinel->prev;
    for(i = 0; i < list->size; i++)
    {
        printf(" %f ", temp->value);
        temp = temp->prev;
    } */
}

/**
 * Reverses the deque.
 */
void circularListReverse(struct CircularList* list)
{
	// FIXME: you must write this
    /* Assert list is valid, create pointers for temp and link */
    assert(list);
    struct Link* temp;
    struct Link* link;
    
    /* printf("\nreverse front %g back %g \n", circularListFront(list), circularListBack(list));
    Used for testing */
    
    link = list->sentinel->prev; /* Initialize link to back */
    temp = link->prev; /* Initialize temp to second to last */
 
    while(temp != list->sentinel)
    {
       /* printf("\nBeg: L:%g %g<-L L->%g t: %g t->%g %g<-t", link->value, link->prev->value,link->next->value, temp->value, temp->next->value, temp->prev->value);
        Used for testing */
        
        temp->next = temp->prev; /* Update temp pointers */
        temp->prev = link;
        
        link->next = link->prev; /* Update link pointers */
        link->next = temp;
        
        link = temp; /* Update link to have value of temp and temp to have value of next */
        temp = temp->next;
       
      /* printf("\nEnd: L:%g %g<-L L->%g t: %g t->%g %g<-t", link->value, link->prev->value,link->next->value, temp->value, temp->next->value, temp->prev->value);
       Used for testing */
    }
    list->sentinel->next = temp->prev;
    list->sentinel->prev = link;
    /* printf("\nfront: %g back: %g \n", list->sentinel->next->value, list->sentinel->prev->value);
     Used for testing */
}
