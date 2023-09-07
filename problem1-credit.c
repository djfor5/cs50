#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    // GET USER INPUT FOR CARD NUMBER
    long long cardNumber;
    do
    {
        printf("Enter card number: ");
        scanf("%lld", &cardNumber);
    } while (cardNumber < 1);

    // CALCULATE CARD LENGTH IN NUMBER OF DIGITS
    long long number = cardNumber;
    int digit;
    int cardLength = 0;
    while (number > 0)
    {
        digit = number % 10;
        number = number / 10;
        cardLength++;
    }

    // CONVERT CARD NUMBER INTO AN ARRAY OF DIGITS
    number = cardNumber;
    digit = 0;
    int cardNumberArr[cardLength];
    for (int i = cardLength - 1; i >= 0; i--)
    {
        digit = number % 10;
        number = number / 10;
        cardNumberArr[i] = digit;
    }

    // PRINT ARRAY OF CARD NUMBER DIGITS
    printf("Card number is: ");
    for (int i = 0; i < cardLength; i++)
    {
        printf("%i", cardNumberArr[i]);
    }
    printf("\n");

    // STEP 1 OF CALCULATING CHECKSUM FOR CARD NUMBER VALIDITY
    int checksum = 0;
    int num;
    for (int i = cardLength - 2; i >= 0; i -= 2)
    {
        num = cardNumberArr[i];
        // printf("cardNumberArr[i] is: %i\n", cardNumberArr[i]);
        if ((2 * num) >= 10)
        {
            checksum += 1 + (2 * num) % 10;
        }
        else
        {
            checksum += 2 * num;
        }
        printf("Interim checksum is: %i\n", checksum);
    }

    // STEP 2 OF CALCULATING CHECKSUM FOR CARD NUMBER VALIDITY
    for (int i = cardLength - 1; i >= 0; i -= 2)
    {
        num = cardNumberArr[i];
        checksum += num;
        printf("Interim checksum is: %i\n", checksum);
    }

    printf("Final checksum is: %i\n", checksum);

    // STEP 3 OF CALCULATING CHECKSUM FOR CARD NUMBER VALIDITY
    if (checksum % 10 != 0)
    {
        return printf("INVALID\n");
    }

    // CHECK IF VISA
    if (cardNumberArr[0] == 4 && (cardLength == 13 || cardLength == 16))
    {
        return printf("VISA\n");
    }

    // CHECK IF AMEX
    bool isAmex = cardNumberArr[0] == 3 && (cardNumberArr[1] = 4 || cardNumberArr[1] == 7) && cardLength == 15;
    if (isAmex)
    {
        return printf("AMEX\n");
    }

    // CHECK IF MASTERCARD
    bool isMasterCard = cardNumberArr[0] == 5 && (cardNumberArr[1] = 1 || cardNumberArr[1] == 2 || cardNumberArr[1] == 3 || cardNumberArr[1] == 4 || cardNumberArr[1] == 5) && cardLength == 16;
    if (isMasterCard)
    {
        return printf("MASTERCARD\n");
    }

    return printf("INVALID\n");

    return 0;
}

// VALID NUMBER TO TEST
// 4003600000000014 -> VISA