/* CS261- Assignment 1 - Q.3*/
/* Name:    Patrick Mullaney
 * Date:    1/17/17
 * Solution description:  Simple program to sort an array of integers.
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>

void sort(int* number, int n){
     /*Sort the given array number , of length n*/
    int i, j;
    
    // Standard bubble sort.
    for(i = 0; i < n; i++)
    {
        for(j = i+1; j < n; j++)
        {
            if(number[i] > number[j])
            {
                int temp = number[i];
                number[i] = number[j];
                number[j] = temp;
            }
        }
    }
}

int main(){
    /*Declare an integer n and assign it a value of 20.*/
    int n = 20;
    int i;
    
    /*Allocate memory for an array of n integers using malloc.*/
    int *array;
    array = malloc(sizeof(n));
    /*Fill this array with random numbers, using rand().*/
    /* Set limit to 50 to keep numbers managable for testing */
    for(i = 0; i < n; i++)
    {
        array[i] = rand()%50;
    }
    /*Print the contents of the array.*/
    printf("Before sort: ");
    for(i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    /*Pass this array along with n to the sort() function of part a.*/
    sort(array, n);
    /*Print the contents of the array.*/
    printf("\nAfter sort: ");
    for(i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    return 0;
}
