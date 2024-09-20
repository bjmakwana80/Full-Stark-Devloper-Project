// write a pro to print highest of three nums using function -> fun(n1, n2, n3) -> return (highest of three nums)

#include <stdio.h>

int find_highest(int n1, int n2, int n3)
{
    int highest;
    if (n1 >= n2)
    {
        if (n1 >= n3)
        {
            highest = n1;
        }
        else
        {
            highest = n3;
        }
    }
    else
    {
        if (n2 >= n3)
        {
            highest = n2;
        }
        else
        {
            highest = n3;
        }
    }

    return highest;
}

int main()
{
    int num1, num2, num3;
    printf("Enter number 1 : ");
    scanf("%d", &num1);
    printf("Enter number 2 : ");
    scanf("%d", &num2);
    printf("Enter number 3 : ");
    scanf("%d", &num3);

    printf("highest number = %d ", find_highest(num1, num2, num3));
    return 0;
}