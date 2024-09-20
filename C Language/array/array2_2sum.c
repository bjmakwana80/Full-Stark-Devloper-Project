#include<stdio.h>
int main()
{
    int mark[5][5];

     printf("ENTER 1st SUDENTS MARK :-\n");

    printf("ENTER 1 SUBJECT MARK : ");
    scanf("%d",&mark[0][0]);

    printf("ENTER 2 SUBJECT mark : ");
    scanf("%d",&mark[0][1]);

    printf("ENTER 3 SUBJECT MARK : ");
    scanf("%d",&mark[0][2]);

    printf("ENTER 4 SUBJECT MARK : ");
    scanf("%d",&mark[0][3]);

    printf("ENTER 5 SUBJECT MARK : ");
    scanf("%d",&mark[0][4]);

    printf("\n ");
    printf("%10d",mark[0][0]);
    printf("%10d",mark[0][1]);
    printf("%10d",mark[0][2]);
    printf("%10d",mark[0][3]);
    printf("%10d",mark[0][4]);

    int sum=0;
    sum = mark[0][0] + mark[0][1] + mark[0][2] + mark[0][3] + mark[0][4];
    printf("\tSUM = %d",sum);

    

    return 0;
}