// check if a student pass or fail -> marks > 45 => pass | marks <= 45 => fail
#include <stdio.h>
#include <stdbool.h>
bool checkpass_fail(int number)
{
    if (number >= 45)
    {
        return true;
    }
    return false;
}

int main()
{
    int mark;
    printf("Enter student mark : ");
    scanf("%d", &mark);
    
    if(mark <= 100)
    {
        if (checkpass_fail(mark))
        {
            printf("pass");
        }
        else
        {
            printf("fail");
        }
    }
    else
    {
        printf("Invalid Input");
    }

    return 0;
}