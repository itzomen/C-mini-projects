#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

//Functions
void push(void);
void pop(void);
void display_stack(void);
void stack_size(void);
void topOfStack(void);


int main(){
    //Do until input is zero
    printf("\n\t IMPLEMENTATION OF LINKED LIST IN C \t\n");
    printf("\n Create your Stack by entring the size of the Stack: \t");
    scanf("%d", &n);

    do{

        printf("\n\t Choose an option: \t\n");
        printf("\n\t 1.PUSH \n\t 2.POP \n\t 3.Display Stack Elements \n\t 4.Size of Stack \n\t 5.Top of Stack \n\t 0.Exit Program \t");
        printf("\n\n\t");
        scanf("%d", &option);
        switch(option)
        {
            case 1:
                {
                  system("cls");
                  printf("\n\t__________________________________________________\t\t\n");
                  //push();
                  printf("\n\t__________________________________________________\t\t\n");
                  break;
                }
            case 2:
                {
                  system("cls");
                  printf("\n\t__________________________________________________\t\t\n");
                  //pop();
                  printf("\n\t__________________________________________________\t\t\n");
                  break;
                }
            case 3:
                {
                  system("cls");
                  printf("\n\t__________________________________________________\t\t\n");
                  //display_stack();
                  printf("\n\t__________________________________________________\t\t\n");
                  break;
                }
            case 4:
                {
                  system("cls");
                  printf("\n\t__________________________________________________\t\t\n");
                  //stack_size();
                  printf("\n\t__________________________________________________\t\t\n");
                  break;
                }
                case 5:
                {
                  system("cls");
                  printf("\n\t__________________________________________________\t\t\n");
                  //topOfStack();
                  printf("\n\t__________________________________________________\t\t\n");
                  break;
                }
            default:
                {
                    system("cls");
                    printf("\n\t__________________________________________________\t\t\n");
                    printf("\n Invalid option or program is exiting: \n");
                    printf("\n\t__________________________________________________\t\t\n");
                }
        }

    }while(option != 0);
    return 0;
}

