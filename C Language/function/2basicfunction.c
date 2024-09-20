//create a function that prits sum of three numbers

#include <stdio.h>

void printSUM(int sum)
{
    printf("Sum = %d",sum);
}

void main()
{

    int num1, num2 , num3;
    printf("Enter a number 1 : ");
    scanf("%d", &num1);

    printf("Enter a number 2 : ");
    scanf("%d",&num2);

    printf("Enter a number 3 : ");
    scanf("%d",&num3);

    printSUM(num1+num2+num3);
}