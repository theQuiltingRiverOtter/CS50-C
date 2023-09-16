#include <cs50.h>
#include <stdio.h>

int get_number_length(long number);
string get_card_type(int length, long number);
bool validate(int length, long number);

int main(void) 
{
 
    long card_number = get_long("Number: ");
    int card_number_length = get_number_length(card_number);

   string card_type = get_card_type(card_number_length, card_number);
   printf("%s\n", card_type);
    
    
}

int get_number_length(long number){
    int length;
    if (number / 1000000000000000 > 0){
        return 16;
    } 
    else if (number / 100000000000000 > 0){
        return 15;
    } else if (number / 1000000000000 > 0){
        return 13;
    }
    else {
        return 0;
    }
}

string get_card_type(int length, long number){
    string card_type;
    bool isValid = validate(length, number);
    if (isValid != true){
        return "INVALID";
    }
    if (length == 13) {
        int starting_number = number / 1000000000000000;
        if (starting_number == 4){
            card_type = "VISA";
        }
        else {
            return "INVALID";
        }  
    } 
    else if (length == 15 ) {
        int starting_number = number / 10000000000000;
        if (starting_number == 34 || starting_number == 37){
            card_type = "AMERICAN EXPRESS";
        } 
        else {
            return "INVALID";
        }
        
    } else if (length == 16) {
        int starting_number_single_digit = number / 1000000000000000;
        int starting_number_double_digit = number / 100000000000000;
        if ( starting_number_single_digit== 4){
            card_type = "VISA";
        } 
        else if (starting_number_double_digit >= 51 && starting_number_double_digit <= 55){
            card_type = "MASTERCARD";
        }
        else {
            return "INVALID";
        }
    } 
    else {
        return "INVALID";
    }
    return card_type;

}

bool validate(int length, long number){
    int sum = 0;
    long divisor = 1;
    long place = 10;
    int other_sum = 0;
    int total_sum = 0;
    for( int i = 0; i < length;i++){
        if (i % 2 != 0){
            int product = (number / divisor % 10) * 2;
            if (product < 10){
                sum += product;
            }
            else {
                int first_digt = product % 10;
                int second_digt = product /10;
                sum += first_digt + second_digt;
            }
        }
        else {
            other_sum += (number / divisor % 10);
        }

        divisor *= 10;
    }
    total_sum = sum + other_sum;
    if (total_sum % 10 == 0){
        return true;
    }
    else {
        return false;
    }
    
}