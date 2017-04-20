/* CS261- Assignment 2, part 1.*/
/* Name: Patrick Mullaney
 * Date: 1/20/17
 * Solution description:  Program to implement dynamic array functions.
 */
/*	dynamicArray.c: Dynamic Array implementation. */
#include <assert.h>
#include <stdlib.h>
#include "dynArray.h"

struct DynArr
{
	TYPE *data;		/* pointer to the data array */
	int size;		/* Number of elements in the array */
	int capacity;	/* capacity ofthe array */
};

/* ************************************************************************
	Dynamic Array Functions
************************************************************************ */

/* Initialize (including allocation of data array) dynamic array.

	param: 	v		pointer to the dynamic array
	param:	cap 	capacity of the dynamic array
	pre:	v is not null
	post:	internal data array can hold cap elements
	post:	v->data is not null
*/
void initDynArr(DynArr *v, int capacity)
{
	assert(capacity > 0);
	assert(v!= 0);
	v->data = (TYPE *) malloc(sizeof(TYPE) * capacity);
	assert(v->data != 0);
	v->size = 0;
	v->capacity = capacity;	
}

/* Allocate and initialize dynamic array.

	param:	cap 	desired capacity for the dyn array
	pre:	none
	post:	none
	ret:	a non-null pointer to a dynArr of cap capacity
			and 0 elements in it.		
*/
DynArr* newDynArr(int cap)
{
	assert(cap > 0);
	DynArr *r = (DynArr *)malloc(sizeof( DynArr));
	assert(r != 0);
	initDynArr(r,cap);
	return r;
}

/* Deallocate data array in dynamic array. 

	param: 	v		pointer to the dynamic array
	pre:	none
	post:	d.data points to null
	post:	size and capacity are 0
	post:	the memory used by v->data is freed
*/
void freeDynArr(DynArr *v)
{
	if(v->data != 0)
	{
		free(v->data); 	/* free the space on the heap */
		v->data = 0;   	/* make it point to null */
	}
	v->size = 0;
	v->capacity = 0;
}

/* Deallocate data array and the dynamic array ure. 

	param: 	v		pointer to the dynamic array
	pre:	none
	post:	the memory used by v->data is freed
	post:	the memory used by d is freed
*/
void deleteDynArr(DynArr *v)
{
	freeDynArr(v);
	free(v);
}

/* Resizes the underlying array to be the size cap 

	param: 	v		pointer to the dynamic array
	param:	cap		the new desired capacity
	pre:	v is not null
	post:	v has capacity newCap
*/
void _dynArrSetCapacity(DynArr *v, int newCap)
{	
	/* FIXME: You will write this function */
    assert(newCap > 0); /* Check new cap valid and array is not null */
    assert(v != 0);
    DynArr* newV = newDynArr(newCap);
    int newSize = sizeDynArr(v);
    int i;
    for(i = 0; i < newSize; i++)
    {
        /* copy from old array */
        addDynArr(newV, getDynArr(v, i));
    }
                                                // free old array?
}

/* Get the size of the dynamic array

	param: 	v		pointer to the dynamic array
	pre:	v is not null
	post:	none
	ret:	the size of the dynamic array
*/
int sizeDynArr(DynArr *v)
{
	return v->size;
}

/* 	Adds an element to the end of the dynamic array

	param: 	v		pointer to the dynamic array
	param:	val		the value to add to the end of the dynamic array
	pre:	the dynArry is not null
	post:	size increases by 1
	post:	if reached capacity, capacity is doubled
	post:	val is in the last utilized position in the array
*/
void addDynArr(DynArr *v, TYPE val)
{
	/* FIXME: You will write this function */
   /* If size reaches capacity */
    if(v->size == v->capacity)
    {
        /* Resize x 2 */
        _dynArrSetCapacity(v,(v->capacity * 2));
    }
   // printf(" add %d size: %d \n", val, v->size);          *** used for testing
    v->data[v->size] = val;
    v->size = v->size+1;
}

/*	Get an element from the dynamic array from a specified position
	
	param: 	v		pointer to the dynamic array
	param:	pos		integer index to get the element from
	pre:	v is not null
	pre:	v is not empty
	pre:	pos < size of the dyn array and >= 0
	post:	no changes to the dyn Array
	ret:	value stored at index pos
*/

TYPE getDynArr(DynArr *v, int pos)
{
	/* FIXME: You will write this function */
    /* Assert valid position */
    assert(pos >= 0);
    assert(pos < v->size);

	/* FIXME: you must change this return value */
    /* Return data at position */
    return v->data[pos];
}

/*	Put an item into the dynamic array at the specified location,
	overwriting the element that was there

	param: 	v		pointer to the dynamic array
	param:	pos		the index to put the value into
	param:	val		the value to insert 
	pre:	v is not null
	pre:	v is not empty
	pre:	pos >= 0 and pos < size of the array
	post:	index pos contains new value, val
*/
void putDynArr(DynArr *v, int pos, TYPE val)
{
	/* FIXME: You will write this function */
    /* Assert valid position */
    assert(v);
    assert(pos >= 0);
    assert(pos < v->size);
    /* Put new value into position */
    v->data[pos] = val;
}

/*	Swap two specified elements in the dynamic array

	param: 	v		pointer to the dynamic array
	param:	i,j		the elements to be swapped
	pre:	v is not null
	pre:	v is not empty
	pre:	i, j >= 0 and i,j < size of the dynamic array
	post:	index i now holds the value at j and index j now holds the value at i
*/
void swapDynArr(DynArr *v, int i, int  j)
{
	/* FIXME: You will write this function */
    /* Assert v is not empty and i and j are valid positions) */
    assert(v);
    assert((i >= 0) && (j >= 0));
    assert((i < v->size) && (j < v->size));
    /* Swap elements */
    TYPE temp;
    temp = v->data[i];
    v->data[i] = v->data[j];
    v->data[j] = temp;
}

/*	Remove the element at the specified location from the array,
	shifts other elements back one to fill the gap

	param: 	v		pointer to the dynamic array
	param:	idx		location of element to remove
	pre:	v is not null
	pre:	v is not empty
	pre:	idx < size and idx >= 0
	post:	the element at idx is removed
	post:	the elements past idx are moved back one
*/
void removeAtDynArr(DynArr *v, int idx)
{
	/* FIXME: You will write this function */
    /* Assert v is not null and that idx is valid position */
    assert(v);
    assert((idx < v->size) && (idx >= 0));
    /* Shift all values over 1, starting at idx */
    int i;
    for(i = idx; i < v->size; i++)
    {
        v->data[i] = v->data[i+1];
    }
    /* Set last position of array to 0, then decrement size of array */
    v->data[v->size] = 0;
    v->size--;
}



/* ************************************************************************
	Stack Interface Functions
************************************************************************ */

/*	Returns boolean (encoded in an int) demonstrating whether or not the 
	dynamic array stack has an item on it.

	param:	v		pointer to the dynamic array
	pre:	the dynArr is not null
	post:	none
	ret:	1 if empty, otherwise 0
*/
int isEmptyDynArr(DynArr *v)
{
	/* FIXME: You will write this function */
    /* Assert v s not null */
    assert(v);
    int val;
    val = 1;
    /* If v is not empty, return 0 */
    if(v->data[v->size-1] != 0)
    {
        val = 0;
        
    }
	/* FIXME:  You will change this return value*/
	return val;
}

/* 	Push an element onto the top of the stack

	param:	v		pointer to the dynamic array
	param:	val		the value to push onto the stack
	pre:	v is not null
	post:	size increases by 1
			if reached capacity, capacity is doubled
			val is on the top of the stack
*/
void pushDynArr(DynArr *v, TYPE val)
{
	/* FIXME: You will write this function */
    /* Assert v is not null */
    assert(v);
    /* Add an element to top of stack */
    v->data[v->size] = val;
    /* Increment size */
    v->size++;
    /* If size reaches capacity, resize array */
    if(v->size == v->capacity)
    {
        _dynArrSetCapacity(v,(v->capacity * 2));
    }
}

/*	Returns the element at the top of the stack

	param:	v		pointer to the dynamic array
	pre:	v is not null
	pre:	v is not empty
	post:	no changes to the stack
*/
TYPE topDynArr(DynArr *v)
{
	/* FIXME: You will write this function */
    /* Assert v is not null */
    assert(v);
	/* FIXME: You will change this return value*/
    /* If not null, return element at the top */
	return v->data[v->size-1];
}

/* Removes the element on top of the stack 

	param:	v		pointer to the dynamic array
	pre:	v is not null
	pre:	v is not empty
	post:	size is decremented by 1
			the top has been removed
*/
void popDynArr(DynArr *v)
{
	/* FIXME: You will write this function */
    /* Assert v is not valid */
    assert(v);
    /* Remove top element */
    v->data[v->size-1] = 0;
    /* Decrement size */
    v->size--;
}

/* ************************************************************************
	Bag Interface Functions
************************************************************************ */

/*	Returns boolean (encoded as an int) demonstrating whether or not
	the specified value is in the collection
	true = 1
	false = 0

	param:	v		pointer to the dynamic array
	param:	val		the value to look for in the bag
	pre:	v is not null
	pre:	v is not empty
	post:	no changes to the bag
*/
int containsDynArr(DynArr *v, TYPE val)
{
	/* FIXME: You will write this function */
    /* Assert v is not null */
    assert(v);
    int contain, i;
    /* Initialize contain to 0 */
    contain = 0;
    for(i = 0; i < v->size; i++)
    {
        if(v->data[i] == val)
        {
            contain = 1; /* If match is found, update to 1 */
        }
    }
	
	/* FIXME:  You will change this return value */
	return contain;
}

/*	Removes the first occurrence of the specified value from the collection
	if it occurs

	param:	v		pointer to the dynamic array
	param:	val		the value to remove from the array
	pre:	v is not null
	pre:	v is not empty
	post:	val has been removed
	post:	size of the bag is reduced by 1
*/
void removeDynArr(DynArr *v, TYPE val)
{
	/* FIXME: You will write this function */
    /* Assert v is not null */
    assert(v);
    int match, i;
    /* Initialize match to 0 */
    match = 0;
    while(match == 0)
    {
        for(i = 0; i < v->size; i++)
        {
            /* If match is found, remove element and update match */
            if(v->data[i] == val)
            {
                removeAtDynArr(v, i);
                match = 1;
            }
        }
        if((i == v->size) && (match == 0))
        {
            match = 1; /*If looped through array and no match found, break while loop */
        }
    }
}
