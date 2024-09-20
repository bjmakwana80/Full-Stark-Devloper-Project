#include <stdio.h>
void main()
{
    int c, r;
    int num;
    printf("ENTER PATTERN NO : ");
    scanf("%d",num);
    if(num>=0)
    for (c = 1; c <= 5; c++)
    {
        for (r = 1 ; r < c; r++)
        {
            printf(" ");
        }
        for (r = 5; r >= c ; r--)
        {
            printf("* ");
        }
        printf("\n");
    }
}

