#include <stdio.h>
int main()
{
    int mark[5][5];
    int row, colum;

    for (row = 0; row < 5; row++)
    {
        printf("-------------------------------\n");
        printf("ENTER %d SUDENTS MARK :-\n", row + 1);
        printf("-------------------------------\n");
        for (colum = 0; colum < 5; colum++)
        {
            printf("ENTER %d SUBJECT MARK : ", colum + 1);
            scanf("%d", &mark[row][colum]);
        }
    }
    for (row = 0; row < 5; row++)
    {
        printf("\n ");
        for (colum = 0; colum < 5; colum++)
            printf("%10d", mark[row][colum]);
        int sum = 0;
        sum = mark[row][colum] + mark[row][colum] + mark[row][colum] + mark[row][colum] + mark[row][colum];
        printf("\tSUM = %d", sum);
    }
    return 0;
}