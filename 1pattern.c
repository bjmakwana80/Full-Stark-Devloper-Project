#include<stdio.h>
void main()
{
    int i, j;
    int count;
    printf("ENTER PATTERN NO : ");
    scanf("%d",&count);
    
{
    if (count >= 0)
    
    {
        for (i = 1; i <= count; i++) 
        { 
            for (j = count; j >=i; j--) 
            {
                if (i == 1 || i == count || j == 1 || j == i) 
                {
                    printf("* ");
                }
                else 
                {
                    printf("  ");
                }
            }
            printf("\n");
        }
    } 
    else 
    {
        printf("Invalid input ");
    }
}

}