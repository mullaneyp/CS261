/* CS261- Assignment 2, part 3.*/
/* Name: Patrick Mullaney
 * Date: 1/20/17
 * Solution description:  Program to implement stack functions by checking for balanced
 * parantheses, braces, and brackets.
 */
/*	stack.c: Stack application. */
#include <stdio.h>
#include <stdlib.h>
#include "dynArray.h"


/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
	param: 	s pointer to a string 	
	pre: s is not null		
*/
char nextChar(char* s)
{
	static int i = -1;	
	char c;
	++i;	
	c = *(s+i);			
	if ( c == '\0' )
		return '\0';	
	else 
		return c;
}

/* Checks whether the (), {}, and [] are balanced or not
	param: 	s pointer to a string 	
	pre: s is not null	
	post:	
*/
int isBalanced(char* s)
{
	/* FIXME: You will write this function */
    DynArr* paranStack;
    paranStack = newDynArr(10);
   
    char top;
    /* paran, brace, and bracket are used as a boolean value to determine whether 
       a corresponding character is in the stack */
    int paran, brace, bracket;
    paran = 0;
    brace = 0;
    bracket = 0;
    
    top = nextChar(s);
    
    while(top != '\0')
    {
        /* check paranthesis */
        if(top == '(')
        {
            /* printf("Push ( "); used for testing */
            pushDynArr(paranStack, top);
            paran = 1;
        }
        else if(top == ')')
        {
            /* printf("Pop )"); used for testing */
            if(paran == 1)
            {
                popDynArr(paranStack);
                paran = 0;
            }
        }
        else if(top == '{')
        {
            /*printf("Push { "); used for testing */
            pushDynArr(paranStack, top);
            brace = 1;
        }
        else if(top == '}')
        {
             /*  printf("Pop }"); used for testing */
            if(brace == 1)
            {
                popDynArr(paranStack);
                brace = 0;
            }
        }
        else if(top == '[')
        {
            /* printf("Push ["); used for testing */
            pushDynArr(paranStack, top);
            bracket = 1;
        }
        else if(top == ']')
        {
            if(bracket == 1)
            {
                /* printf("Pop ]"); used for testing */
                popDynArr(paranStack);
                bracket = 0;
            }
        }
        top = nextChar(s);
    }
    int balance;
    balance = 0;
    if(isEmptyDynArr(paranStack))
    {
       /* printf("Paranthesis balanced, top: %d\n", top); used for testing */
        balance = 1;
    }
    else
    {
        balance = 0;
    }
    return balance;
}

int main(int argc, char* argv[]){
	
   char* s=argv[1];
    
    // char* s = "({[x + y] + q} + z)"; /* Used to test a variety of strings in IDE */
    
	int res;
	
	printf("Assignment 2\n");

	res = isBalanced(s);
    /* printf("res: %d\n", res); used during testing */

	if (res)
		printf("The string %s is balanced\n",s);
	else 
		printf("The string %s is not balanced\n",s);
	
	return 0;	
}

