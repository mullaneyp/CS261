/* CS261- Assignment 1 - Q.5*/
/* Name:  Patrick Mullaney
 * Date:  1/16/17
 * Solution description: Simple program that takes a word and converts it to sticky caps.
 */
 
#include <stdio.h>
#include <stdlib.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
     return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
     return ch-'A'+'a';
}

void sticky(char* word){
    
     /*Convert to sticky caps*/
    int i;//, k;
    /* Check length of string */
    //k = strlen(word);
    
    for(i = 0; i < strlen(word); i++)
    {
        if((i%2) == 0) /* If i is even, char should be upper case */
        {
            /* If lower case, change to upper */
            if((word[i] >= 'a') && (word[i] <= 'z'))
            {
                word[i] = toUpperCase(word[i]);
            }
        }
        else /* If i is odd, char should be lower case */
        {
            /* Check if upper case, change to lower */
            if((word[i] >= 'A') && (word[i] <= 'Z'))
            {
                word[i] = toLowerCase(word[i]);
            }
        }
    }

}

int main(){
    /*Read word from the keyboard using scanf*/
    char word[10];
    printf("Please enter a word.\n");
    scanf("%s", word);
   
    /*Call sticky*/
    sticky(word);
    
    /*Print the new word*/
    printf("Word: %s\n", word);
    
    return 0;
}