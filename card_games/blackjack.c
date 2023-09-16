#include <stdio.h>
#include <cs50.h>

const int DECK_SIZE = 52;

int main(void)
{
    string suites[4] = {"hearts", "diamonds", "clubs", "spades"};
    string values[13] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K'};
    string deck[DECK_SIZE];
    int deck_ind = 0;
    string card;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            // combine two string values into one
        }
    }
    for (int x = 0; x < DECK_SIZE; x++)
    {
        printf("%s", deck[x]);
    }
}
