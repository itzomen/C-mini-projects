#include <stdio.h>
#include <stdlib.h>

//variables
int option;

struct node{
    int data;
    struct node *next;
};

//Functions
void addAtBeginning(void);


int main(){
    //Do until input is zero
    printf("\n\t IMPLEMENTATION OF LINKED LIST IN C \t\n");

    do{

        printf("\n\t Choose an option: \t\n");
        printf("\n\t 1.Add Element at the  Beginning \n\t 2.Add Element at the  End \n\t 3.Add Element at a specific position \n\t 4.Delete Linked list \n\t 5.Display Linked list \n\t 0.Exit Program \t");
        printf("\n\n\t");
        scanf("%d", &option);
        switch(option)
        {
            case 1:
                {
                  system("cls");
                  printf("\n\t__________________________________________________\t\t\n");
                  void addAtBeginning(void);
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
void addAtBeginning(){

}
