/* CS261- Assignment 1 - Q.4*/
/* Name: Patrick Mullaney
 * Date: 1/16/17
 * Solution description: Simple program for sorting an array of n students.
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student{
	int id;
	int score;
};

void sort(struct student* students, int n){
     /*Sort the n students based on their score*/
    int i, j;
    
    for(i = 0; i < n; i++)
    {
        for(j = i+1; j < n; j++)
        {
            if(students[i].score > students[j].score)
            {
                struct student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}
int main(){
    
    /*Declare an integer n and assign it a value.*/
    int n = 20;

    /*Allocate memory for n students using malloc.*/
    struct student *array = malloc(n * sizeof(struct student));
    
    /*Generate random and unique IDs and random scores for the n students, using rand().*/

    int i, j, k;
    for(i = 0; i < n; i++)
    {
        int newID = 0;
        int match = 0;
 
        k = rand()%n+1;

        /* Generate random and unique ID */
        while(newID == 0)
        {
            match = 0;
            k = rand()%n+1;
            /* Check for match */
            for(j = 0; j < i; j++)
            {
                if(k == array[j].id)
                {
                    match = 1;
                }
            
            }
            /* If ID not yet taken, can create new ID, break loop */
            if(match == 0)
            {
               newID = 1;
            }
        }
        /* Assign new ID */
        array[i].id = k;
        /* Generate random score */
        array[i].score = rand()%100+1;
    }

    /*Print the contents of the array of n students.*/
    for(i = 0; i < n; i++)
    {
        printf("ID%d Score %d\n", array[i].id, array[i].score);
    }
    
    /*Pass this array along with n to the sort() function*/
    sort(array, n);
    
    /*Print the contents of the array of n students.*/
    for(i = 0; i < n; i++)
    {
        printf("ID%d Score %d\n", array[i].id, array[i].score);
    }
    return 0;
}
