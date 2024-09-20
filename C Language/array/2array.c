// create array for int, float, char; size = 10; and print all element

#include<stdio.h>
int main()
{
    int arr1[10];
    // arr1[0] = 1;
    // arr1[1] = 2;
    // arr1[2] = 3;
    // arr1[3] = 4;
    // arr1[4] = 5;
    // arr1[5] = 6;
    // arr1[6] = 7;
    // arr1[7] = 8;
    // arr1[8] = 9;
    // arr1[9] = 10;

    // printf("%d \n", arr1[0]);
    // printf("%d \n", arr1[1]);
    // printf("%d \n", arr1[2]);
    // printf("%d \n", arr1[3]);
    // printf("%d \n", arr1[4]);
    // printf("%d \n", arr1[5]);
    // printf("%d \n", arr1[6]);
    // printf("%d \n", arr1[7]);
    // printf("%d \n", arr1[8]);
    // printf("%d \n", arr1[9]);

        
    for (int i = 0; i <= 9; i++) 
    { 
        // arr1[i] = i +1;
        printf("Enter %dth elemet : ", i);
        scanf("%d", &arr1[i]);
    }
    for (int i = 0; i <= 9; i++)
     {
        printf("%d ", arr1[i]);
    }

    return 0;
}