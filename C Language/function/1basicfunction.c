//create a function that prits sum of two numbers

#include <stdio.h>

void print2sum(int sum)
{
    printf("Sum = %d",sum);
}

void main()
{

    int num1, num2;
    printf("Enter a number 1 : ");
    scanf("%d", &num1);

    printf("Enter a number 2 : ");
    scanf("%d",&num2);

    print2sum(num1+num2);
}