#include <stdio.h>
void main()
{
    int colum, row;
    for (colum = 1; colum <= 5; colum++)
    {
        for (row = 5; row >=colum; row--)
        {
            printf("  ");
        }

        for (row = 1; row < colum; row++)
        {
            printf("@ ");
        }
        printf("\n");
    }
}