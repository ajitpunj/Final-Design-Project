#include <stdio.h>
volatile int * istart = (int *) 0xFF200000;
int main(void)
{
int i,start,error=0;
char junk[20];
do{
printf("\nEnter 1 to start:\n");
scanf("%d", &start);
//scanf("%s",junk);
//if(start == 1){
//error = 1;
//}
}while(start != 1);

*(istart)= 0;
*(istart) = 1;
return 0;
}
