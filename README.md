# million-occurrences
This is a c program that reads the characters from a source text file and outputs the words and number of occurrences of each word in a text file named output

# C program to count the occurrences of all the distinct words in a file

//v1 opens the input file and displays output on the screen 
//v2 opens two files and save output to file named output

I want to create a dynamic array so that it will be able to read approximately one million words but i'm having issues doing that.

The limited number of words it can read now is approximately 40000 using stack allocation.
I have tried using malloc and realloc to create a dynamic array using the snippet bellow but i ran into issues with the string functions i.e 
exeption error
msvcrt.dll!strcpy or after some modification i get msvcrt.dll!msvcrt?_strcpy

# snippet
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
    
    
    HELP
