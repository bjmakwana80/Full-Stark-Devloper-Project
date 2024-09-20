#include<stdio.h>
void main() {

    int num = 7;
/*
    printf("%d ", num); // 7

    num += 7; // num = num + 7 // num = 14
    printf("%d ", num); // 14

    num += 7; // num = num + 7 // num = 21
    printf("%d ", num); // 21

    num += 7; // num = 28
    printf("%d ", num); // 28

*/

    for (int i = 1; i <= 10; i++) {
        printf("%d \n", num);
        num += 7;
    }
    // 7 * 1 = 7
    // 7 * 2 = 14
    // 7 * 3 = 21
    // 7 * 4 = 28
    // 7 * 5 = 35
    //
}