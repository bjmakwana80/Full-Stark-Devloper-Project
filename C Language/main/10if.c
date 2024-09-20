// write a c program to findout qube of given positive number
#include<stdio.h>
void main()
{
    //create/define variable
    int number,qube;
    printf("enter number");
    scanf("%d",&number);
    //condition
    if(number<0) // < > <= >= ==
    {
        number= 0 - number;
        printf("number was negative so converted into positive number");
    }
    // process
    qube = number * number * number; //expression
    printf("\nqube = %d",qube);
}