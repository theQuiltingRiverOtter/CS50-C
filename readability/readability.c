#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int get_letter_count(string text);
int get_word_count(string text);
int get_sentence_count(string text);
int get_readability(int letter_count, int word_count, int sentence_count);

int main(void)
{
    string text = get_string("Text: ");

    int letter_count = get_letter_count(text);
    int word_count = get_word_count(text);
    int sentence_count = get_sentence_count(text);
    int grade_level = get_readability(letter_count, word_count, sentence_count);

    if (grade_level >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade_level < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", grade_level);
    }
}

int get_letter_count(string text)
{
    int n = strlen(text);
    int length = 0;
    for (int i = 0; i < n; i++)
    {
        int charCode = (int)text[i];
        if (charCode > 64 && charCode < 91)
        {
            length++;
        }
        else if (charCode > 96 && charCode < 123)
        {
            length++;
        }
    }
    return length;
}

int get_word_count(string text)
{
    int n = strlen(text);
    int word_count = 0;
    for (int i = 0; i < n; i++)
    {
        int charCode = (int)text[i];
        if (charCode == 32)
        {
            word_count++;
        }
    }
    word_count++;
    return word_count;
}

int get_sentence_count(string text)
{
    int n = strlen(text);
    int sentence_count = 0;
    for (int i = 0; i < n; i++)
    {
        int charCode = (int)text[i];
        if (charCode == 33 || charCode == 63 || charCode == 46)
        {
            sentence_count++;
        }
    }
    return sentence_count;
}

int get_readability(int letter_count, int word_count, int sentence_count)
{
    float L = (letter_count / (float)word_count) * 100;
    float S = (sentence_count / (float)word_count) * 100;
    float readabilty = (0.0588 * L) - (0.296 * S) - 15.8;
    int grade_level = (int)round(readabilty);
    return grade_level;
}