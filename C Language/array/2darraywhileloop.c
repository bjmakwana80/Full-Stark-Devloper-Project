#include <stdio.h>
int main()
{
    int mark[4][5] = {{5, 5, 4, 3, 7}, {7, 5, 6, 4, 3}, {7, 8, 4, 5, 7}, {5, 4, 3, 6, 2}};
    int sub = 100;
    int r = 0;
    while (r < 4)
    {
        int c = 0;
        while (c < 5)
        {
            printf("%4d ", mark[r][c]);
            sub = sub - mark[r][c];
            printf("subvalue = %2d ",sub);
            c++;
        }
        printf("\n");
        r++;
    }
            printf("\n subvalue = %d",sub);

    return 0;
}