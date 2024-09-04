#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

void Hesaplayici(string text, int textLenght);
int CLIMethod(float kelime, float cumle, float harf);
void SinifBelirleme(int gelenDeger);

int harfSayisi = 0;
int kelimeSayisi = 1;
int cumleSayisi = 0;

int main(void)
{
    string inputText = get_string("Text: ");

    int textLenght = strlen(inputText);

    Hesaplayici(inputText, textLenght);
    int index = CLIMethod(kelimeSayisi, cumleSayisi, harfSayisi);

    SinifBelirleme(index);
}
void Hesaplayici(string text, int textLenght)
{
    for (int i = 0; i < textLenght; i++)
    {
        if (isalnum(text[i]))
        {
            harfSayisi++;
        }
        else if (text[i] == 32)
        {
            kelimeSayisi++;
        }
        else if (text[i] == 46 || text[i] == 63 || text[i] == 33) // just ? . !
        {
            cumleSayisi++;
        }
    }
}
int CLIMethod(float kelime, float cumle, float harf)
{
    float L = (harf / kelime) * 100;
    float S = (cumle / kelime) * 100;
    float index = (0.0588f * L) - (0.296f * S) - 15.8f;
    return round(index);
}
void SinifBelirleme(int gelenDeger)
{
    string gonderilecekText;

    if (gelenDeger <= 1)
        printf("Before Grade 1\n");
    else if (gelenDeger >= 16)
        printf("Grade 16+\n");
    else
        printf("Grade %i\n", gelenDeger);
}
