#include<stdio.h>
void main()
{

 /*
   for (int i = 1; i <= 1; i++) 
   {
        printf(" %d",i);
   }
        printf("\n");

     for (int i = 1; i <= 2; i++) 
   {
        printf(" %d",i);
   }
        printf("\n");

     for (int i = 1; i <= 3; i++) 
   {
        printf(" %d",i);
   }
        printf("\n");

     for (int i = 1; i <= 4; i++) 
   {
        printf(" %d",i);
   }
        printf("\n");

      for (int i = 1; i <= 5; i++) 
   {
     printf(" %d",i);
   }
        printf("\n");
*/
     int num;
     printf("ENTER NUMBER : ");
     scanf("%d",&num);

     for(int count = 0; count <= num; count++)
     {
          for (int i = 1; i <= count; i++) 
   {
        printf(" %d",i);
   }
        printf("\n");
     }

} 