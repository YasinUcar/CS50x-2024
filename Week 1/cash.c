#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    float money;
    do
    {

        money = get_float("Geri verilecek tutar: ");
    }
    while (money < 0);
    int quarter = 25, dime = 10, nickel = 5, penny = 1;
    int geriVerilecekTutar = 0;
    int money2 = 0;
    if (money < 1)
    {
        money = (int) round(money * 100);
    }

    while (money > 0)
    {
        if (money >= quarter)
        {
            geriVerilecekTutar++;
            money -= quarter;
        }
        else if (money >= dime)
        {
            geriVerilecekTutar++;
            money -= dime;
        }
        else if (money >= nickel)
        {
            geriVerilecekTutar++;
            money -= nickel;
        }
        else if (money >= penny)
        {
            geriVerilecekTutar++;
            money -= penny;
        }
        else
        {
            break;
        }
    }
    printf("%i\n", geriVerilecekTutar);
}
