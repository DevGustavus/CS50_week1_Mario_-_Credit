#include <stdio.h>
#include <cs50.h>

int main(void){
    long card_number = 0;

    card_number = get_long("Credit number: ");

    printf("%ld", card_number);
}
