#include <stdio.h>
#include <cs50.h>


int main(void)
{
    int x = get_int("First Number: ");
    int y = get_int("Second Number: ");
    int z = x * y;
    printf("What do you think\n");
    if (z < 100)
    {
        printf("%d is less than 100\n", z);
    }
    else if (z > 100) 
    {
        printf("%d is greater than 100\n", z);
    } else
    {
        printf("%d is equal to 100\n", z);
    }
    
}