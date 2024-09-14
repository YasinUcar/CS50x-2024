// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

string replace(string text);
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Geçerli bir değer giriniz!\n");
        return 1;
    }
    printf("%s\n", replace(argv[1]));
    return 0;
}
string replace(string text)
{
    int leets[] = {6, 3, 1, 0};
    int textLenght = strlen(text);

    for (int i = 0; i < textLenght; i++)
    {
        char gelenMetin = tolower(text[i]);

        switch (gelenMetin)
        {
            case 'a':
                text[i] = '6';
                break;
            case 'e':
                text[i] = '3';
                break;
            case 'i':
                text[i] = '1';
                break;
            case 'o':
                text[i] = '0';
                break;
            default:
                break;
        }
    }
    return text;
}
