#include <stdio.h>
#include <cs50.h>

int count_digits(long number);
void extract_digits(long number, int digits[], int size);
int luhn_algorithm(int digits[], int size);
string determine_card_type(int digits[], int size);

int main(void) {
    long card_number = get_long("Credit number: ");
    int size = count_digits(card_number);

    int numbers[size];

    extract_digits(card_number, numbers, size);

    int sum = luhn_algorithm(numbers, size);

    string card_type = determine_card_type(numbers, size);

    if (sum % 10 != 0) {
        printf("INVALID\n");
    } else {
        printf("%s\n", card_type);
    }

    return 0;
}

int count_digits(long number) {
    int size = 0;
    while (number != 0) {
        number /= 10;
        size++;
    }
    return size;
}

void extract_digits(long number, int digits[], int size) {
    for (int i = 0; i < size; i++) {
        digits[i] = number % 10;
        number /= 10;
    }

    for (int i = 0, j = size - 1; i < j; i++, j--) {
        int temp = digits[i];
        digits[i] = digits[j];
        digits[j] = temp;
    }
}

int luhn_algorithm(int digits[], int size) {
    int sum = 0;
    for (int i = size - 2; i >= 0; i -= 2) {
        int digit = digits[i] * 2;
        sum += digit / 10 + digit % 10;
    }

    for (int i = size - 1; i >= 0; i -= 2) {
        sum += digits[i];
    }

    return sum;
}

string determine_card_type(int digits[], int size) {
    int first_digit = digits[0];
    int second_digit = digits[1];

    if (size == 15 && first_digit == 3 && (second_digit == 4 || second_digit == 7)) {
        return "AMEX";
    } else if (size == 16 && first_digit == 5 && (second_digit >= 1 && second_digit <= 5)) {
        return "MASTERCARD";
    } else if ((size == 13 || size == 16) && first_digit == 4) {
        return "VISA";
    } else {
        return "INVALID";
    }
}
