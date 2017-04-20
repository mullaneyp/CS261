/* CS261- Assignment 1 - Q.1*/
/* Name:  Patrick Mullaney
 * Date:  1/16/17
 * Solution description:  Simple program that generates array of struct students with random
 * IDs and scores.
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student{
	int id;
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
    struct student *studentArray;
    studentArray = (struct student*)malloc(10 *sizeof(studentArray));
     /*return the pointer*/
    return (studentArray);
}

void generate(struct student* students){
     /*Generate random and unique ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
    
    struct student* stud = students;
    int i, j, k;
    
    for(i = 0; i < 10; i++)
    {
        int newID = 0;
        int match = 0;
        
        k = rand()%10+1;
        /* Generate random and unique ID */
        do
        {
            match = 0;
            k = rand()%10+1;
            /* Check for match */
            for(j = 0; j < i; j++)
            {
                if(k == stud[j].id)
                {
                    match = 1;
                }
            }
            /* If ID number is not yet taken, can create new ID */
            if(match == 0)
            {
                newID = 1;
            }
        }while(newID == 0);
        /* Assign new ID */
        stud[i].id = k;
        /* Generate random score */
        stud[i].score = rand()%100+1;
    }
}

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
    struct student* stud = students;
    int i;
    /* Loop through and print scores */
    for(i = 0; i < 10; i++)
    {
        printf("ID%d Score %d\n", stud[i].id, stud[i].score);
    }
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
    int i;
    float min = 0.0f;
    float max = 0.0f;
    float sum = 0.0;
    float avg = 0.0;
    
    /* Set min and max to first score */
    min = students[0].score;
    max = students[0].score;
    
    
    /* Find min */
    for(i = 1; i < 10; i++)
    {
        if(students[i].score < min)
        {
            min = students[i].score;
        }
    }
    /* Find max */
    for(i = 1; i < 10; i++)
    {
        if(students[i].score > max)
        {
            max = students[i].score;
        }
    }
    /* Compute average */
    for(i = 0; i < 10; i++)
    {
        sum = (sum + students[i].score);
    }
    avg = sum/10;
    
    /* Print results */
    printf("Summary: \nMin: %.1f\nMax: %.1f\nAverage: %.1f\n", min, max, avg);
}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
    if(stud != 0)
    {
        free(stud);
    }
}

int main(){
    struct student* st = 0;
    
    /*call allocate*/
    st = allocate();
    /*call generate*/
    generate(st);
    /*call output*/
    output(st);
    /*call summary*/
    summary(st);
    /*call deallocate*/
    deallocate(st);
    
    return 0;
}
