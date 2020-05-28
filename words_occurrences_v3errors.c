/*C program to count the occurrences of all the distinct words in a file.*/
/*By Peng Boris Akebuon*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

//#define MAX_WORDS 100//stack allocation approximately limited to 40000

int main(){

    FILE *fp, *fpo;
    int i, j, temp, length, Distinct;
    int n = 40;//character length
    char ch[n];
    int index = 0;//keeps track of words

    //array of words
    char word[n];
    
    //char words[MAX_WORDS][n];
    /*char **words = (char**)malloc(MAX_WORDS * sizeof(char*));
    for ( i = 0; i < MAX_WORDS; i++)
    {
        words[i] = (char*)malloc(40+1);
    }*/
    
    
    

    size_t MAX_WORDS = 1000;
    char **words = (char**)malloc(MAX_WORDS * sizeof(*words));
    if (words == NULL){
         printf("mem not allocated\n");
         printf("Verify the path and try again\n");
         getchar();
         exit(EXIT_FAILURE);
        }
    if (MAX_WORDS == index+1)
    {
        MAX_WORDS *= 2;
        words = (char**)realloc(words, MAX_WORDS * sizeof(*words));
        if (words == NULL){
         printf("mem no aloc\n");
         printf("Verify the path and try again\n");
         getchar();
         exit(EXIT_FAILURE);
        }
    }
    
    
    

    //variable to count distinct words
    int count[MAX_WORDS];
    
    
   /*opening file*/
    fp = fopen("complete-shakespeare.txt", "r");
    fpo = fopen("output.txt", "w");

    /*checking if the file was opened*/
    if (fp == NULL || fpo == NULL)
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

    

    while (fscanf(fp, "%s", word) != EOF)
    {
        /* convert word to lowercase */
        //strlwr(*word);

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
    
    fprintf(fpo, "\nS/N \t WORD \t\t FREQUENCY\n");
    
    for ( i = 0; i < index; i++)
    { 
        //%-10s print string in 10 character width and left justified
        //%d makes number printed right justified
        fprintf(fpo, "\n%d \t %-10s \t %d \n", i+1, words[i], count[i]);
    }
    
     getchar();
 return 0;
}