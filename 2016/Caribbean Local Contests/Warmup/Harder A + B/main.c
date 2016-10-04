#include <stdio.h>      /* scanf(), printf() */
#include <stdlib.h>     /* EXIT_SUCESS */

int
main(void)
{
    /*
     * The unsigned integer type is not necessary as int can represent 10^9
     * (the maximum value of an input operand) but it is used in order to not
     * have to deal with any implicit type conversion/promotion in the
     * calculation of the output expression.
     */
    unsigned A, B;

    scanf("%u %u", &A, &B);

    /*
     * The output expression has an unsigned integer type because either input
     * operand can be a maximum of 10^9 so their maximum sum is 2 * 10^9 and
     * that sum is doubled in the output expression, so the maximum output
     * value is 4 * 10^9, which cannot represented as a signed 32-bit integer.
     */
    printf("%u\n", 2u * (A + B));

    return EXIT_SUCCESS;
}
