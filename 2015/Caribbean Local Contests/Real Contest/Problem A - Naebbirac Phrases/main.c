#include <stdio.h>      /* printf(), getchar_unlocked() */

#define MAX_LEN 100

int
main(void)
{
    int ch;
    int T;              /* test cases */
    int phrase[MAX_LEN + 1];   /* +1 to buffer ' ' character */
    int *p;             /* used to scan input string */
    int differences;

    T = 0;
    while ((ch = getchar_unlocked()) != '\n')
        T = 10 * T + (ch ^ '0');

    for (; T; T--) {
        p = phrase;
        while ((*p = getchar_unlocked()) != ' ')
            p++;

        differences = 0;
        p = phrase;
        while ((ch = getchar_unlocked()) != '\n') {
            if (*p != ch)
                differences++;

            p++;
        }

        printf("%d\n", differences);
    }

    return 0;
}
