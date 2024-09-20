// calculate area of circle 

#include<stdio.h>
float getcircle(float radius,float area)
{

  return 3.14159265359 * radius * radius; 
}
int main()
{
    float radius = 0;
    float area = 0;
    printf("Enter of radius value : ");
    scanf("%f",&radius);


     printf("area = %.7f ", getcircle(radius,area));

    return 0;
}