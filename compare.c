#include <stdio.h>
#include <assert.h>
#include "bst.h"
#include "structs.h"

/*----------------------------------------------------------------------------
 very similar to the compareTo method in java or the strcmp function in c. it
 returns an integer to tell you if the left value is greater then, less then, or
 equal to the right value. you are comparing the number variable, letter is not
 used in the comparison.

 if left < right return -1
 if left > right return 1
 if left = right return 0
 */

 /*Define this function, type casting the value of void * to the desired type.
  The current definition of TYPE in bst.h is void*, which means that left and
  right are void pointers. To compare left and right, you should first cast
  left and right to the corresponding pointer type (struct data *), and then
  compare the values pointed by the casted pointers.

  DO NOT compare the addresses pointed by left and right, i.e. "if (left < right)",
  which is really wrong.
 */
int compare(TYPE left, TYPE right)
{
    /*FIXME: write this*/
    assert((left!= 0) && (right!= 0));
    struct data* dLeft = (struct data*)left;
    struct data* dRight = (struct data*)right;
 
    // try 1- seg fault
   /* if(left == NULL)
    {
        printf("left null \n");
    }
    if(dLeft->number == 0)
    {
        printf("left num == 0\n");
        return -1;
    }
    else if(dLeft->number < dRight->number)
    {
        return -1;
    }
    else if(dLeft->number > dRight->number)
    {
        return 1;
    }
    else if(dLeft->number == dRight->number)
    {
        return 0;
    } */
    
    // try 2
   // printf("Left: %d, right: %d\n", dLeft->number, dRight->number);
    if(dLeft->number < dRight->number)
    {
     //   printf("Compare: dLeft: %d less than dRight %d\n", dLeft->number, dRight->number);
        return -1;
    }
    else if(dLeft->number > dRight->number)
    {
     //   printf("Compare: dLeft: %d greater than dRight %d\n", dLeft->number, dRight->number);
        return 1;
    }
    else if(dLeft->number == dRight->number)
    {
        //printf("Compare equal \n");
        return 0;
    }
	return 0;
}

/*Define this function, type casting the value of void * to the desired type*/
void print_type(TYPE curval)
{
    /*FIXME: write this*/
    struct data* value = curval;
    int dataNum = value->number;
    char* dataName = value->name;
   
    printf("Number: %d Name: %s\n", dataNum, dataName);
}


