#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "functions.h"

int findIncompleteQuotient(int dividend, int divisor)
{
    bool is_negative = (dividend < 0) != (divisor < 0);

    dividend = abs(dividend);
    divisor = abs(divisor);

    int incomplete_quotient = 0;
    while (dividend >= divisor)
    {
        dividend -= divisor;
        ++incomplete_quotient;
    }
    if (is_negative)
    {
        incomplete_quotient = -incomplete_quotient;
        if (dividend != 0)
        {
            --incomplete_quotient;
        }
    }
    return incomplete_quotient;
}

int main()
{
    printf("Enter the dividend\na = ");
    int number1 = getNum();

    printf("\nEnter the divisor\nb = ");
    int number2 = getNum();

    if (number2 == 0)
    {
        printf("\nError: Division by zero\n");
        return 0;
    }

    int incompleteQuotient = findIncompleteQuotient(number1, number2);
    printf("\nResult of an incomplete quotient: %d\n", incompleteQuotient);
}