#include <stdio.h>
int main()
{
    int mark[4][5] = {{5, 5, 4, 3, 7}, {7, 5, 6, 4, 3}, {7, 8, 4, 5, 7}, {5, 4, 3, 6, 2}};
    int sub = 100;
    int r = 0;
    
    do
    {
        int c = 0;
        do
        {
            printf("%d ",mark[r][c]);
            sub = sub - mark[r][c];
            printf("subvalue = %2d ",sub);
            c++;
        }
        while (c < 5);
        printf("\n");
        r++;
    }
    while(r < 4);
         printf("subvalue = %2d ",sub);

    return 0;
}