#include<stdio.h>
void main()
{
    int key;
    printf("ENTER PATTERN KEY : ");
    scanf("%c", &key);

    int num;
    printf("ENTER PATTERN NUMBAR : ");
    scanf("%d",&num);

    
        for(int colum = num ; colum >= 1 ; colum--)
        {
            for(int row = 1 ; row <= colum ; row++)
            {
                printf("%c ",key);
            }
            printf("\n");
        }

    
}