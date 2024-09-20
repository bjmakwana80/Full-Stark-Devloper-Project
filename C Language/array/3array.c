#include<stdio.h>
int main()
{
    char array[10];

for (char i = 0; i <= 9; i++) 
    { 
        
        printf("Enter %dth elemet : ", i);
        scanf("%c", &array[i]);
    }
   for (char i = 0; i <= 9; i++)
     {
        printf("%c ", array[i]);
    }
    

    return 0;
}