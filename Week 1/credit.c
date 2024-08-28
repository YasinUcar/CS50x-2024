#include <cs50.h>
#include <stdio.h>
int ToplamHaneBul(long number);
int IlkikiHaneBulucu(long number);
void Dogrulama(int toplamHane, int rakamlarToplam, int ilkIkiSayi);
int main(void)
{
    long creditNumber;
    int geriKalanSayilarToplam = 0, rakamlarToplami = 0, sondanOncekiSayilarToplam = 0;

    do
    {
        creditNumber = get_long("Credit Number: ");
    }
    while (creditNumber <= 0);

    int ilkIkıHane = IlkikiHaneBulucu(creditNumber);
    int toplamHaneSayisi = ToplamHaneBul(creditNumber);

    while (creditNumber > 0)
    {
        geriKalanSayilarToplam += creditNumber % 10;
        creditNumber /= 10;
        int sondanOncekiSayilar = creditNumber % 10;
        creditNumber /= 10;

        int sondanOncekiSayilarCarpim = sondanOncekiSayilar * 2;

        sondanOncekiSayilarToplam +=
            (sondanOncekiSayilarCarpim % 10 + sondanOncekiSayilarCarpim / 10);
    }
    rakamlarToplami = geriKalanSayilarToplam + sondanOncekiSayilarToplam;
    if (rakamlarToplami % 10 == 0)
        Dogrulama(toplamHaneSayisi, rakamlarToplami, ilkIkıHane);
    else
        printf("INVALID\n");
}
void Dogrulama(int toplamHane, int rakamlarToplam, int ilkIkiSayi)
{
    if (toplamHane == 15 && (ilkIkiSayi == 34 || ilkIkiSayi == 37))
        printf("AMEX\n");
    else if ((toplamHane == 13 || toplamHane == 16) && ilkIkiSayi / 10 == 4)
        printf("VISA\n");
    else if (toplamHane == 16 && (ilkIkiSayi >= 51 && ilkIkiSayi <= 55))
        printf("MASTERCARD\n");
    else
        printf("INVALID\n");
}

int ToplamHaneBul(long number)
{
    int totalDigit = 0;
    while (number > 0)
    {
        number /= 10;
        totalDigit++;
    }
    return totalDigit;
}
int IlkikiHaneBulucu(long number)
{
    int ilkIkıHane;
    while (number >= 100)
    {
        ilkIkıHane = number /= 10;
    }
    return ilkIkıHane;
}
