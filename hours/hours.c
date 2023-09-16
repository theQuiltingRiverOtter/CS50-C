#include <stdio.h>
#include <cs50.h>
#include <string.h>

float calculate_hours(float hours[], char type, int weeks);

int main()
{
    int weeks = get_int("Number of weeks taking CS50: ");
    float hours[weeks];
    for (int i = 0; i < weeks; i++)
    {
        float hour = get_float("Week %d HW Hours: ", i);
        hours[i] = hour;
    }
    char type = get_char("Enter T for total hours, A for average hours per week: ");
    float calculated = calculate_hours(hours, type, weeks);
    printf("%f\n", calculated);
}

float calculate_hours(float hours[], char type, int weeks)
{
    float sum = 0;
    for (int i = 0; i < weeks; i++)
    {
        sum += hours[i];
    }
    if ((int)type == 84)
    {
        return sum;
    }
    else if ((int)type == 65)
    {
        return sum / weeks;
    }
    else
    {
        return 0;
    }
}
