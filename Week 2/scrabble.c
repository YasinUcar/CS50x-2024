#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

int get_string_lenght(string text);
string CompareAnswers(string player1, string player2);
string TextUpper(string text, int textLenght);
string CheckTheWinner(int point1, int point2);

int main(void)
{
    string player1Answer = get_string("Player 1: ");
    string player2Answer = get_string("Player 2: ");

    string winner = CompareAnswers(player1Answer, player2Answer);
    printf("%s\n", winner);
}

string CompareAnswers(string player1, string player2)
{

    // TEXT LENGHT
    int p1AnswerLenght = get_string_lenght(player1);
    int p2AnswerLenght = get_string_lenght(player2);

    // UPPERTEXT
    player1 = TextUpper(player1, p1AnswerLenght);
    player2 = TextUpper(player2, p2AnswerLenght);

    int const POINTS[] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                          1, 1, 3, 10, 1, 1, 1, 1, 1, 4, 8, 4, 10};
    int totalP1 = 0, totalP2 = 0;
    int const FARK = 'A';

    for (int i = 0; i < p1AnswerLenght; i++)
    {
        if (player1[i] >= 'A' && player1[i] <= 'Z')
        {
            int puan = player1[i] - FARK;
            totalP1 += POINTS[puan];
        }
    }
    for (int i = 0; i < p2AnswerLenght; i++)
    {
        if (player2[i] >= 'A' && player2[i] <= 'Z')
        {
            int puan = player2[i] - FARK;
            totalP2 += POINTS[puan];
        }
    }
    return CheckTheWinner(totalP1, totalP2);
}
int get_string_lenght(string text)
{
    int sayi = 0;

    while (text[sayi] != '\0')
        sayi++;
    return sayi;
}
string TextUpper(string text, int textLenght)
{
    for (int i = 0; i < textLenght; i++)
    {
        text[i] = toupper(text[i]);
    }
    return text;
}

string CheckTheWinner(int point1, int point2)
{
    if (point1 > point2)
        return "Player 1 wins!";
    else if (point2 > point1)
        return "Player 2 wins!";
    else
        return "Tie!";
}
