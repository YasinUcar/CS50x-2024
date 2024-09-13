#include <cs50.h>
#include <stdio.h>

bool prime(int number);

int main(void)
{
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

bool prime(int number)
{
    // TODO
    //amele edition
    int kalansizBolenSayisi = 0;
    for (int i = 1; i <= number; i++)
    {
        if (number % i == 0)
        {
            kalansizBolenSayisi++;
        }
        if (kalansizBolenSayisi >= 2 && i < number)
        {
            return false;
        }
        else if (kalansizBolenSayisi == 2)
            return true;
    }
    return false;
}
