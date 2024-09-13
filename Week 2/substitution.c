#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
bool is_digit(string argvText);
char Sifrele(char letter, string key);
string errorMessage = "";
int main(int argc, string argv[])
{

    if (argc != 2 || !is_digit(argv[1]))
    {
        printf("%s\n", errorMessage);
        return 1;
    }

    string keyText = argv[1];
    string plainText = get_string("plaintext: ");
    int textLenght = strlen(plainText);

    char cipherText[textLenght + 1];

    for (int i = 0; i < textLenght; i++)
    {
        cipherText[i] = Sifrele(plainText[i], keyText);
    }
    cipherText[textLenght] = '\0';
    printf("ciphertext: %s\n", cipherText);

    return 0;
}

bool is_digit(string argvText)
{

    int textLenght = strlen(argvText);
    string tempText = argvText;
    if (textLenght != 26)
    {
        errorMessage = "Key must contain 26 characters.";
        return false;
    }
    for (int i = 0; i < textLenght; i++)
    {
        if (!isalpha(argvText[i]))
        {
            errorMessage = "Usage: ./substitution key";
            return false;
        }
        for (int j = i + 1; j < textLenght; j++)
        {
            int sameCharacter = 0;
            if (tempText[i] == argvText[j])
            {
                sameCharacter++;
                if (sameCharacter >= 1)
                {
                    errorMessage = "Not same characters";
                    return false;
                }
            }
        }
    }
    return true;
}

char Sifrele(char letter, string key)
{

    int ci;
    if (islower(letter))
    {
        ci = letter - 97;
        return tolower(key[ci]);
    }
    else if (isupper(letter))
    {
        ci = letter - 65;
        return toupper(key[ci]);
    }
    else
        return letter;
}
