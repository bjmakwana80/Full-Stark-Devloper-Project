// num of pair in 1d array which sum = key {key = 10}
// int arr[] = {5,2,6,5,8,-2...};

#include <stdio.h>

int main()
{
    int keysum[] = {6, 8, 3, 2, 7, -3, -6, 4, 2, -6, -5};
    int key = 10;
    int sum = 0;
    int i;
    int size = sizeof(keysum) / sizeof(keysum[0]);
    for (i = 0; i < 11; i++)
    {
        
        printf("\n%d + %d ", keysum[i], sum);
        sum += keysum[i];
        printf("Sum = %d", sum);
    }
{if(sum == 10);
        {
        printf("This sum number matches the key");
        }
    }    
    return 0;
}