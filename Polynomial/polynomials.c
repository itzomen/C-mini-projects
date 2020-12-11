#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Poly_Node{ 
  int coef;
  int exp;
  struct Poly_Node *link;  
};

//functions
void insertTerms(struct Poly_Node **,int,int);
void display(struct Poly_Node *);

int main(){
    //Do until input is zero
    printf("\n\t IMPLEMENTATION OF POLYNOMIAL WITH Linked List IN C \t\n");
    printf("\n Create your two polynomials i.e P(x) and Q(x): \t");
    //creating polynomials structures
    struct Poly_Node *start_p=NULL,*start_q=NULL,*start_r=NULL;
    //vars
    int i,n,c,e;

    do{

        printf("\n\t Choose an option: \t\n");
        printf("\n\t 1.ENQUEUE \n\t 2.DEQUEUE \n\t 3.Display queue Elements \n\t 4.Size of queue \n\t 5.Head of queue \n\t 6.End of queue \n\t 0.Exit Program \t");
        printf("\n\n\t");
        scanf("%d", &option);
        switch(option)
        {
            case 1:
                {
                  system("cls");
                  printf("\n\t__________________________________________________\t\t\n");
                  enqueue();
                  printf("\n\t__________________________________________________\t\t\n");
                  break;
                }
            case 2:
                {
                  system("cls");
                  printf("\n\t__________________________________________________\t\t\n");
                  dequeue();
                  printf("\n\t__________________________________________________\t\t\n");
                  break;
                }
            case 3:
                {
                  system("cls");
                  printf("\n\t__________________________________________________\t\t\n");
                  display_queue();
                  printf("\n\t__________________________________________________\t\t\n");
                  break;
                }
            case 4:
                {
                  system("cls");
                  printf("\n\t__________________________________________________\t\t\n");
                  queue_size();
                  printf("\n\t__________________________________________________\t\t\n");
                  break;
                }
                case 5:
                {
                  system("cls");
                  printf("\n\t__________________________________________________\t\t\n");
                  headOfQueue();
                  printf("\n\t__________________________________________________\t\t\n");
                  break;
                }
                case 6:
                {
                  system("cls");
                  printf("\n\t__________________________________________________\t\t\n");
                  endOfQueue();
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

void insertTerms(){
}

void display(){
}