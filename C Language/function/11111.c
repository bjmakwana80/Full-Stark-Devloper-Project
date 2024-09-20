// Write a programe to findout area of circle
#include <stdio.h>
void main()
{
    float pi = 3.141592;
    float radius = 0;
    float answer = 0;
    printf("Enter value of radius ");
    scanf("%f", &radius);

    answer = pi *radius *radius;
    printf("\nThe value of answer is %.4f ",answer);
}