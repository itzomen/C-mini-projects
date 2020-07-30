//program calculate the number of ones and zeros in binary numbers for a given range
//developed to calculate the binary numbers with  equal ones and zeros
//set variable n which is the range and variable m which is the number of ones against zeros per bit
//by Peng Boris Akebuon
//for any questions -> peng.akebuon2468@gmail.com
#include <stdio.h>
#include <math.h>
//colors
#define CYN "\x1B[36m"
#define YEL "\x1B[33m"
#define RESET "\x1B[0m"

int i, j, t=0;//variables to move through values
int a[10];//array to store each bit
int equal_bits = 0;//variable to count equal bit binary numbers

//set variable n and m
int n = 65536;//number of bits raised to the power of 2
int m = 8;//number of ones against zeros per bit

int main(){

  
  for (i=0; i<n; i++)//for storing each number
  {

    int ones=0, zeros=0;//initiating number of zero and one for each number
    t+= i;//assigning number to evaluate if not program will enter a loop
    printf(CYN"________________________________________________________________________________\n"RESET);
    printf("\n");
    printf("val %d = %d\n", i, t);
    
    if (t > 0)
    {
      for (j = 0; t > 0; j++)//for storing each bit
       {
         a[j] = t%2;
         t = t/2;
       }
    }
    else
    {
      a[j] = 0;
    }
   
    printf("bin %d = ", i);

    for (j = j - 1; j >= 0; j--)
       {
         
         printf("%d", a[j]);//printing binary values per bits

         if (a[j]==1)//calculating ones and zeros
         {
           ones += 1;
         }
         else
         {
           zeros += 1;
         }

       }

       printf("\n");
   
    printf("ones = %d\n", ones);
    printf("zeros = %d\n", zeros);

    if (ones==m)
         {
           equal_bits += 1;
         } 
     
    printf("\n");
  }
  
  printf(YEL"Binary numbers with  equal ones and zeros in the range 0 to %d is %d\n"RESET, n, equal_bits);   
  printf("\n");
return 0;
}
