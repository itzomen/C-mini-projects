/*C program using arrays to implement the stack data structure*/
#include <stdio.h>
#include <stdlib.h>
//MAX is the maximum size of the stack
#define MAX 100

int stack[MAX], n, top=-1, option, x;
//Functions
void push(void);
void pop(void);
void display_stack(void);
void stack_size(void);
void topOfStack(void);


int main(){
    //Do until input is zero
    printf("\n\t IMPLEMENTATION OF STACK WITH ARRAYS IN C \t\n");
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
                  push();
                  printf("\n\t__________________________________________________\t\t\n");
                  break;
                }
            case 2:
                {
                  system("cls");
                  printf("\n\t__________________________________________________\t\t\n");
                  pop();
                  printf("\n\t__________________________________________________\t\t\n");
                  break;
                }
            case 3:
                {
                  system("cls");
                  printf("\n\t__________________________________________________\t\t\n");
                  display_stack();
                  printf("\n\t__________________________________________________\t\t\n");
                  break;
                }
            case 4:
                {
                  system("cls");
                  printf("\n\t__________________________________________________\t\t\n");
                  stack_size();
                  printf("\n\t__________________________________________________\t\t\n");
                  break;
                }
                case 5:
                {
                  system("cls");
                  printf("\n\t__________________________________________________\t\t\n");
                  topOfStack();
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

void push(){
    if(top>=n-1){
        printf("\n\t Your stack is full \t\n");
    }
    else{
        printf("\n\t Enter the value you want to push: ");
        scanf("%d", &x);
        top++;
        stack[top]=x;
    }
}
void pop(){
    if(top<=-1){
        printf("\n\t Your stack is under flow \t\n");
    }
    else{
        printf("\n\t %d has been popped out \t", stack[top]);
        top--;
    }
}
void display_stack(){
    if(top>-1){
        printf("\n\t These are the elements in the stack \t\n");
        printf("\n\t\t Top \t\t\n");
        for(int i=top; i>=0; i--)
            printf("\n\t\t  %d  \t\t\n", stack[i]);
        printf("\n\t\t End \t\t\n");

    }
    else{
        printf("\n\t Your stack is empty \t\n");
    }
}
void stack_size(){
    if(top>-1){
        printf("\n\t The stack size is %d\t\n", top+1);
    }
    else{
        printf("\n\t Your stack is empty \t\n");
    }
}
void topOfStack(){
    if(top>-1){
        printf("\n\t The top of the stack is \t\n");
        printf("\n\t\t Top : %d  \t\t\n", stack[top]);

    }
    else{
        printf("\n\t Your stack is empty \t\n");
    }
}
