#include<stdio.h>
int main()
{
    int mark[4][5] = {{5,5,4,3,7},{7,5,6,4,3},{7,8,4,5,7},{5,4,3,6,2}};
    int r,c;
    int sub=100;
    for(r=0;r<4;r++)
    {
        for(c=0;c<5;c++)
        {
            printf("%3d ",mark[r][c]);
            sub = sub - mark[r][c];
            printf("subvalue = %2d ", sub);

        }
            printf("\n");
    }
            printf("  subvalue = %d", sub);
    
    return 0;
}