/*C program to count the occurrences of all the distinct words in a file.*/
/*By Peng Boris Akebuon*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

#define MAX_WORDS 40000

int main(){

    FILE *fp;
    int i, j, temp, length, Distinct;
    char ch[40];

    //array of words
    char word[40];
    char words[MAX_WORDS][40];
    

    //variable to count distinct words
    int count[MAX_WORDS];
    
    
    /*opening file*/
    fp = fopen("complete-shakespeare.txt", "r");

    /*checking if the file was opened*/
    if (fp == NULL)
    {
       printf("File was not opened\n");
       printf("Verify the path and try again\n");
       getchar();
       exit(EXIT_FAILURE);
    }

    //setting count to zero
    for (i = 0; i < MAX_WORDS; i++)
    {
        count[i] = 0;
    }

    int index = 0;//keeps track of words

    while (fscanf(fp, "%s", word) != EOF)
    {
        /* convert word to lowercase */
        strlwr(word);

        //removin punctuation character
        length = strlen(word);
        if (ispunct(word[length - 1]))
        {
            word[length - 1] = '\0';
        }
        
        //check if word exist in array of words
        Distinct = 1;
        for ( i = 0; i < index && Distinct; i++)
        {
            /*if strings are equal*/
            if (strcmp(words[i], word) == 0)
            {
                Distinct = 0;
            }
            
        }

        //if distinct, add word to array of words
        //increment index 
        //else increment occurrence by incrementing count of word
        if (Distinct)
        {
            /* add word to array of words */
            strcpy(words[index], word);
            count[index]++;

            index++;//for new word to be read
        }
        else
        {
            count[i - 1]++;
        }

    }
    fclose(fp);
    printf("Read succesful, press any key to display the occurrences");
    getchar();
    
    
    //print all words
    system("cls");
    printf("\nOccurrences of all distinct words in the file\n");
    

    for ( i = 0; i < index; i++)
    { 
        //sorting the occurrence from highest to least
        for ( j = i+1 ; j < index; j++)
        {
            // swaping position from highest to least
            if (count[i] < count[j])
            {
                temp = count[i];//holds count temporarily
                strcpy(ch, words[i]);//ch holds words temporarily
                count[i] = count[j];
                strcpy(words[i], words[j]);
                count[j] = temp;
                strcpy(words[j], ch);
            }
            
        }
    }
    
    printf("\nS/N \t WORD \t FREQUENCY\n");
    
    for ( i = 0; i < index; i++)
    { 
        //%-15s print string in 10 character width and left justified
        //%d makes number printed right justified
        printf("\n%d \t %-10s \t %d \n", i+1, words[i], count[i]);
    }
    
     getchar();
 return 0;
}