#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int option, deg_p, deg_q, eval;

//data structure for representation of polynomials
struct Poly_Node{ 
  int coef;
  int exp;
  struct Poly_Node *link;  
};

//creating polynomials structures
struct Poly_Node *start_p=NULL,*start_q=NULL,*start_r=NULL;

//variables used in functions
int i,n,c,e;

//core functions
void insertTerms(struct Poly_Node **,int,int);
void traverse(struct Poly_Node *);

//main functions
void create_poly();
void display_poly();
void degree_poly();
void add_poly(struct Poly_Node **,struct Poly_Node **,struct Poly_Node **);
void eval_poly(struct Poly_Node *,int);
void multiply_poly(struct Poly_Node **,struct Poly_Node **,struct Poly_Node **);

int main(){
    //Do until input is zero
    printf("\n\t IMPLEMENTATION OF POLYNOMIAL WITH Linked List IN C \t\n");
    printf("\n Create your two polynomials i.e P(x) and Q(x): to operate with the functions \t");
    printf("\n");


    do{

        printf("\n\t Choose an option: \t\n");
        printf("\n\t 1.CREATE Polynomials \n\t 2.DISPLAY Polynomials \n\t 3.Degree of P(x) and Q(x) \n\t 4.Add P(x) and Q(x) \n\t 5.Value of P(x) and Q(x) when x is an interger \n\t 6.Multiply P(x) and Q(x) \n\t 0.Exit Program \t");
        printf("\n\n\t");
        scanf("%d", &option);
        switch(option)
        {
            case 1:
                {
                  system("cls");
                  printf("\n\t__________________________________________________\t\t\n");
                  create_poly();
                  printf("\n\t__________________________________________________\t\t\n");
                  break;
                }
            case 2:
                {
                  system("cls");
                  printf("\n\t__________________________________________________\t\t\n");
                  display_poly();
                  printf("\n\t__________________________________________________\t\t\n");
                  break;
                }
            case 3:
                {
                  system("cls");
                  printf("\n\t__________________________________________________\t\t\n");
                  degree_poly();
                  printf("\n\t__________________________________________________\t\t\n");
                  break;
                }
            case 4:
                {
                  system("cls");
                  printf("\n\t__________________________________________________\t\t\n");
                  add_poly(&start_p,&start_q,&start_r);
                  printf("\n\tSum of P(x) and Q(x) equals: ");
                  traverse(start_r);
                  start_r=NULL;
                  printf("\n\t__________________________________________________\t\t\n");
                  break;
                }
                case 5:
                {
                  system("cls");
                  printf("\n\t__________________________________________________\t\t\n");
                  eval_poly(start_p, eval);
                  eval_poly(start_q, eval);
                  printf("\n\t__________________________________________________\t\t\n");
                  break;
                }
                case 6:
                {
                  system("cls");
                  printf("\n\t__________________________________________________\t\t\n");
                  multiply_poly(&start_p,&start_q,&start_r);
                  printf("\n\tProduct of P(x) and Q(x) equals: ");
                  traverse(start_r);
                  start_r=NULL;
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

void insertTerms(struct Poly_Node **start,int c,int e){
  struct Poly_Node *temp,*temp1,*prev;

  if (*start==NULL){
    temp=(struct Poly_Node*)malloc(sizeof(struct Poly_Node));
    if (temp==NULL){
      printf("Poly_Node is not created, Term cannot be inserted\n");
    }
    else{ 
      temp->coef=c;
      temp->exp=e;
      temp->link=NULL;
      *start=temp;
    }
  }
  else{
    temp1=*start;
    while (temp1!=NULL && temp1->exp>e){
      prev=temp1;
      temp1=temp1->link;
    }

    if(temp1==NULL){
      temp=(struct Poly_Node *)malloc(sizeof(struct Poly_Node));
      if (temp==NULL){
      printf("Poly_Node is not created, Term cannot be inserted\n");
      }
      else{ 
        temp->coef=c;
        temp->exp=e;
        temp->link=NULL;
        prev->link=temp;
      }
    }//ENDIF
    else
    {
      if(temp1->exp==e){
        temp1->coef=temp1->coef+c;
      }
      else
      {
        if(temp1==*start){
          temp=(struct Poly_Node *)malloc (sizeof (struct Poly_Node));

            if(temp==NULL){
              printf("Poly_Node is not created\n");
            }
            else
            { 
              temp->coef=c;
              temp->exp=e;
              temp->link=*start;
              *start=temp;

            }
        }//end if
        else
        {
          temp=(struct Poly_Node *)malloc(sizeof(struct Poly_Node));

          if (temp==NULL){
            printf("Poly_Node is not created\n");
          }
          else
          { 
            temp->coef=c;
            temp->exp=e;
            temp->link=temp1;
            prev->link=temp;

          }//endesle
        }
        
      }
      
    }
    
  }
}//end funct

void traverse(struct Poly_Node *start){
  struct Poly_Node *temp;
  temp=start;

  if (temp==NULL){
    printf("Empty polynomial\n");
  }
  else
  {
    while(temp!=NULL){
      printf("%d x^%d",temp->coef,temp->exp);
      temp=temp->link;
      if(temp!=NULL)
        printf(" + ");
      else
        printf("\n");
      
    }
  }
  
}//End Traverse

void display_poly(){
    printf("\n");
    printf("\n\tP(x) = ");
    traverse(start_p);
    printf("\n\tQ(x) = ");
    traverse(start_q);
}

void create_poly(){
  //Getting polynomial coef and exp
    printf("\n\tEnter P(X)!\n");
    printf("\tEnter Number of terms:");
    scanf("%d",&n);
    
    deg_p = 0;
    for(i=0;i<n;i++){
    
      printf("Enter coefficient %d: ", i+1);
      scanf("%d",&c);
      printf("Enter exponent %d: ", i+1);
      scanf("%d",&e);
      if (deg_p < e)
      {
        deg_p = e;
      }
      
      insertTerms(&start_p,c,e);

    }

    printf("\n\tEnter Q(x)!\n");
    printf("\tEnter Number of terms:");
    scanf("%d",&n);

    deg_q = 0;
    for(i=0;i<n;i++){ 
    
    printf("Enter coefficient %d: ", i+1);
    scanf("%d",&c);
    printf("Enter exponent %d: ", i+1);
    scanf("%d",&e);
    if (deg_q < e)
      {
        deg_q = e;
      }
    insertTerms(&start_q,c,e);

  }

}

void degree_poly(){
    printf("\n\tDegree of P(x) = %d ", deg_p);
    printf("\n\tDegree of Q(x) = %d ", deg_q);
}

void add_poly(struct Poly_Node** start_p,struct Poly_Node **start_q,struct Poly_Node** start_r){
  int c,e;
  struct Poly_Node *pptr,*qptr;
  *start_r=NULL;

  pptr=*start_p;
  qptr=*start_q;

  while(pptr!=NULL && qptr!=NULL){
    if (pptr->exp==qptr->exp){
      c=pptr->coef+qptr->coef;
      e=pptr->exp;

      insertTerms(start_r,c,e);

      pptr=pptr->link;
      qptr=qptr->link;
    }
    else
    {
      if (pptr->exp>qptr->exp){
        c=pptr->coef;
        e=pptr->exp;

        insertTerms(start_r,c,e);
        pptr=pptr->link;

      }
      else
      {
        c=qptr->coef;
        e=qptr->exp;
        insertTerms(start_r,c,e);
        qptr=qptr->link;
      }
      
    }
    
  }
  while(pptr!=NULL){
    c=pptr->coef;
    e=pptr->exp;
    insertTerms(start_r,c,e);
    pptr=pptr->link;
  }
  while (qptr!=NULL){
    c=qptr->coef;
    e=qptr->exp;
    insertTerms(start_r,c,e);
    qptr=qptr->link;
  }
  
}//End of function

void eval_poly(struct Poly_Node* poly, int eval){
  struct Poly_Node *temp;
  int total=0;
  temp=poly;
  //get x
  printf("\n Enter value of x :");
  scanf("%d", &eval);

  if (temp==NULL){
    printf("Empty polynomial\n");
  }
  else
  {
    int coeff,expo, expo_result;
    while(temp!=NULL){
      coeff=temp->coef;
      expo=temp->exp;
      

      total = total +  coeff * pow(eval, expo);
      temp=temp->link;
      
    }
    //printf("\n\tPolynomial expo %d coef %d \n",expo, coeff);
    printf("\n\t When x = %d, the polynomial evalautes to %d \n", eval, total);
  }
}

void multiply_poly(struct Poly_Node** start_p,struct Poly_Node **start_q,struct Poly_Node** start_r){
  int c,e;
  struct Poly_Node *pptr,*qptr;
  *start_r=NULL;
  
  pptr=*start_p;
  qptr=*start_q;

  if (*start_p==NULL && *start_q==NULL)
    printf("\nMultiplication of polynomial is not possible!\n");
  else
  {
    while(pptr!=NULL){
      
      qptr=*start_q;
      while(qptr!=NULL){
        
        c=pptr->coef*qptr->coef;
        e=pptr->exp+qptr->exp;
        
        insertTerms(start_r,c,e);
        
        qptr=qptr->link;

      }

      pptr=pptr->link;
   
   }
  
  }
  
}