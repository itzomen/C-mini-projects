/*C program using arrays to implement the stack data structure*/
#include <stdio.h>

int n, top=-1, option;

void push(int x);
void pop();
void display_stack(void);
void stack_size(void);


int main(){

    printf("\n\t STACK WITH ARRAYS IN C \t\n");
    printf("\n Enter the size of the Stack:  ");
    scanf("%d", &n);
    int stack[n];

    do{
        switch(option)
        {
            case 1:
                {
                  void push(x);
                  break;
                }
            case 2:
                {
                  void pop();
                  break;
                }
            case 3:
                {
                  void display_stack();
                  break;
                }
            case 4:
                {
                  void stack_size();
                  break;
                }
            default:
                {
                    printf("\n\t Choose an option: \t\n");
                    printf("\n\t 1.PUSH \n\t 2.POP \n\t 3.Display Stack Elements \n\t 4.Size of Stack \n\t 0.Exit Program \t\n");
                    scanf("%d", &option);
                }
        }

    }while(option != 0);
    return 0;
}
