#include<stdio.h>
int main() {

    int arr1[5];

    // arr1[0] = 10;
    // arr1[1] = 2;
    // arr1[2] = 3;
    // arr1[3] = 4;
    // arr1[4] = 5;

    // printf("%d \n", arr1[0]);
    // printf("%d \n", arr1[1]);
    // printf("%d \n", arr1[2]);
    // printf("%d \n", arr1[3]);
    // printf("%d \n", arr1[4]);
        
    for (int i = 0; i <= 4; i++) { // accessing every element
        // arr1[i] = i * 10;
        printf("Enter %dth elemet : ", i);
        scanf("%d", &arr1[i]);
    }
    for (int i = 0; i <= 4; i++)
     {
        printf("%d ", arr1[i]);
    }
    return 0;
}