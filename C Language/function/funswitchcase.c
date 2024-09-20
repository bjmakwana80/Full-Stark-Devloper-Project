// switch case

#include <stdio.h>
#include <stdbool.h>
bool chekcVowel(char input)
{
    switch (input)
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
        printf("It is an vowel ");
        break;

    default:
        printf("It is an consonant ");
        break;
    }
    return input;
}

int main()
{

    char character;
    printf("Enter a character : ");
    scanf("%c", &character);

    printf("%c",chekcVowel(character));
    return 0;
}