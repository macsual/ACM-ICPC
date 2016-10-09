#include <stdio.h>      /* getchar(), scanf(), printf() */
#include <stdlib.h>     /* EXIT_SUCCESS */

static int sum_digits(int digit_sum);

static int
sum_digits(int digit_sum) {
    if (digit_sum < 10)
        return digit_sum;
    else
        return digit_sum % 10 +  sum_digits(digit_sum/10);
}


int
main(void)
{
    int i;
    int T;  /* test cases (1 <= T <= 50) */

    /*
     * The largest digit sum is 9000. The largest sum will come from the
     * number with the most 9's in it which is 10^1000 - 1 that has 1000
     * consecutive nines, therefore that digit sum is 9 * 1000.
     */
    int digit_sum;

    int ch;

    scanf("%d", &T);

    (void)getchar();    /* consume newline left over by scanf() */

    for (i = 0; i < T; i++) {
        digit_sum = 0;
        while ((ch = getchar()) != '\n')
            /*
             * the bit-masking only works for ASCII character encoding,
             * its supersets and similar encodings
             */
            digit_sum += (ch ^ '0');

        while (digit_sum > 9)
            digit_sum = sum_digits(digit_sum);

        printf("%d\n", digit_sum);
    }

    return EXIT_SUCCESS;
}
