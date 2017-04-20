/* CS261- Assignment 1 - Q.2*/
/* Name:  Patrick Mullaney
 * Date:  1/16/17
 * Solution description: Simple program that alters values of integers.
 */
 
#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
    *(a) = (2 * *(a));
    /*Set b to half its original value*/
    *(b) = (*(b)/2);
    /*Assign a+b to c*/
    c = *(a) + *(b);
  
    /*Return c*/
    return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
    int x = 5;
    int y = 6;
    int z = 7;
    int f;
    /*Print the values of x, y and z*/
    printf("x: %d\ny: %d\nz: %d\n", x, y, z);
    /*Call foo() appropriately, passing x,y,z as parameters*/
    f = foo(&x, &y, z);
    /*Print the value returned by foo*/
    printf("foo: %d\n", f);
    /*Print the values of x, y and z again*/
    printf("x: %d\ny: %d\nz: %d\n", x, y, z);
    /*Is the return value different than the value of z?  Why?*/
    
    /* No, z was passed by value rather than as a pointer, so the contents stored in z were not modified, only the copy was modified within foo. */
    
    return 0;
}
    
    
