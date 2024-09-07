#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

string Sifrele(string plainText, int textLenght, int key);
bool KeyDogrula(int inputArgc, string inputArgv);
int main(int argc, string argv[])
{
    // int argc1 = argc;
    // string argv2 = argv[1];
    bool isKeyValid = KeyDogrula(argc, argv[1]);
    if (isKeyValid)
    {
        string plainText = get_string("plaintext: ");
        int textLenght = strlen(plainText);
        char tempText[textLenght];

        int key = atoi(argv[1]);

        string sifrelenmisText = Sifrele(plainText, textLenght, key);
        // printf("ciphertext: %s\n", sifrelenmisText);
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}
bool KeyDogrula(int inputArgc, string inputArgv)
{

    if (inputArgc == 2 /*&& isdigit(inputArgv[0])*/)
    {
        for (int i = 0, n = strlen(inputArgv); i < n; i++)
        {
            if (!isdigit(inputArgv[i]))
                return false;
        }
        return true;
    }
    return false;
}
string Sifrele(string plainText, int textLenght, int key)
{
    int gelenSayi = 0;
    int c = 0;
    char outputText[textLenght];
    printf("ciphertext: ");
    int lowerUpperASCIINumber = 0;
    for (int i = 0; i < textLenght; i++)
    {
        if (islower(plainText[i]))
            lowerUpperASCIINumber = 97;
        //  plainText[i] = toupper(plainText[i]);
        else if (isupper(plainText[i]))
            lowerUpperASCIINumber = 65;
        if (isalpha(plainText[i]))
        {
            gelenSayi = plainText[i] - lowerUpperASCIINumber;
            int ASCIICode = (gelenSayi + key) % 26;
            outputText[i] = ASCIICode + lowerUpperASCIINumber;
        }
        else
            outputText[i] = plainText[i];
        printf("%c", outputText[i]);
    }
    printf("\n");

    string sifrelenmisText = outputText;
    return sifrelenmisText;
}
