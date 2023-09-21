#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "functions.h"

int findIncompleteQuotient(int dividend, int divisor, int* exitCode)
{
    if (divisor == 0)
    {
        exitCode = -1;
        return 0;
    }
    bool dividendNegative = dividend < 0;
    bool resultNegative = (dividend < 0) != (divisor < 0);

    dividend = abs(dividend);
    divisor = abs(divisor);

    int incompleteQuotient = 0;
    while (dividend >= divisor)
    {
        dividend -= divisor;
        ++incompleteQuotient;
    }

    if (dividendNegative && dividend != 0)
    {
        ++incompleteQuotient;
    }

    return resultNegative ? -incompleteQuotient : incompleteQuotient;
}

int test(void)
{
    int exitCode = 0;
    if (findIncompleteQuotient(-12, 5, &exitCode) != -3)
    {
        return 1;
    }
    if (findIncompleteQuotient(12, -5, &exitCode) != -2)
    {
        return 2;
    }
    if (findIncompleteQuotient(12, 5, &exitCode) != 2)
    {
        return 3;
    }
    if (findIncompleteQuotient(-12, -5, &exitCode) != 3)
    {
        return 4;
    }
    if (findIncompleteQuotient(-12, 0, &exitCode) != 0)
    {
        return 5;
    }
    if (findIncompleteQuotient(12, 0, &exitCode) != 0)
    {
        return 6;
    }
    if (findIncompleteQuotient(12, 12, &exitCode) != 1)
    {
        return 7;
    }
    if (findIncompleteQuotient(-12, -12, &exitCode) != 1)
    {
        return 8;
    }
    if (findIncompleteQuotient(12, 1, &exitCode) != 12)
    {
        return 9;
    }
    if (findIncompleteQuotient(12, -1, &exitCode) != -12)
    {
        return 10;
    }
    if (findIncompleteQuotient(3, 7, &exitCode) != 0)
    {
        return 11;
    }
    if (findIncompleteQuotient(-3, 7, &exitCode) != -1)
    {
        return 12;
    }
    return 0;
}

int main()
{
    if (test() != 0)
    {
        printf("failed %d test", test());
        return -1;
    }
    printf("Enter the dividend\na = ");
    int number1 = getNum();

    printf("\nEnter the divisor\nb = ");
    int number2 = getNum();

    int exitCode = 0;
    int incompleteQuotient = findIncompleteQuotient(number1, number2, &exitCode);

    if (exitCode == -1)
    {
        printf("\nError: Division by zero\n");
        return -1;
    }

    printf("\nResult of an incomplete quotient: %d\n", incompleteQuotient);
}