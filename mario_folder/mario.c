#include <stdio.h>
#include <cs50.h>

int get_size(void);
void print_grid(int size);

int main(void)
{
    int size = get_size();
    print_grid(size);
    
}


void print_left_pyramid(int size, int length){
    for (int j = 0; j < size; j++)
        {
            if (j < size  - length -1)
            {
                printf(" ");
            }
            else 
            {
                printf("#");
            }
        
        }

}
void print_right_pyramid(int size, int length){
    for (int k = 0; k < size; k++)
        {
            if (k < size - size + length + 1)
            {
                printf("#");
            }
            else 
            {
                printf(" ");
            }
        
        }

}

void print_grid(int size)
{
    for (int i = 0; i < size; i++)
    {
        print_left_pyramid(size, i);
        printf(" ");
        print_right_pyramid(size, i);
        printf("\n");
    }

}

int get_size(void)
{
    int n;
    do 
    {
        n = get_int("Enter a number (1-8)  ");
     } while (n <= 0 || n > 8);

    return n;
}