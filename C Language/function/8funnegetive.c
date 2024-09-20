#include <stdio.h>
#include <stdbool.h>

bool checkKey(int num, int key)
{
    int ld;
    while (num != 0)
    {
        ld = num % 10;
        if (ld == key)
        {
            return true;
        }
        num /= 10;
    }
    return false;
}

int main()
{

    int num;
    printf("Enter a number : ");
    scanf("%d", &num);
    int key = 2;
    if (checkKey(num, key))
    {
        printf("number containes value of key ");
    }
    else
    {
        printf("number does not containe value of key ");
    }

    return 0;
}