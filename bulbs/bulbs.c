#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    string message = get_string("Message: ");
    int n = strlen(message);

    for (int i = 0; i < n; i++)
    {
        int charCode = (int)message[i];
        int binary[8];
        for (int k = 0; k < 8; k++)
        {
            if (charCode % 2 == 0)
            {
                binary[k] = 0;
            }
            else
            {
                binary[k] = 1;
            }
            charCode /= 2;
        }

        for (int j = 7; j >= 0; j--)
        {
            print_bulb(binary[j]);
        }
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
