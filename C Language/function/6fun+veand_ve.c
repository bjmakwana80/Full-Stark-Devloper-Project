// check if a number is +ve or -ve using boolean function 

#include<stdio.h>
#include<stdbool.h>
bool checkpositivenegetive(int number) 
{
    if (number >= 0) 
    {
        return true;
    } 
    return false;
}


int main()
{
    int num;
    printf("Enter a number : ");
    scanf("%d", &num);

   if (checkpositivenegetive(num)) 
    {
        printf("It is a positive number ");
    } else {
        printf("It is a negetive number ");
    }


    return 0;
}