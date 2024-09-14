// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and "
               "symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    int lenght = strlen(password);
    bool buyukHarfVarMi = false, kucukHarfVarMi = false, sayiVarMi = false, simgeVarMi = false;
    for (int i = 0; i < lenght; i++)
    {
        if (isupper(password[i]))
            buyukHarfVarMi = true;

        else if (islower(password[i]))
            kucukHarfVarMi = true;

        else if (isalnum(password[i]))
            sayiVarMi = true;

        else if (ispunct(password[i]))
            simgeVarMi = true;
    }
    if (buyukHarfVarMi && kucukHarfVarMi && sayiVarMi && simgeVarMi)
    {
        return true;
    }
    return false;
}
