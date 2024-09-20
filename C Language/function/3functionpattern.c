// create functions for all patterns 

#include <stdio.h>

void print2sum(int sum)
{
    printf("Sum = %d",sum);
}

void main()
{
int ans = 2;

    for (int i = 1; i <= 5; i++) 
    {
        for (int j = 5; j >= i; j--) 
      
        {
            printf("%.2d ", ans);
            ans += 2;
        }
        printf("\n");
    }



    
}