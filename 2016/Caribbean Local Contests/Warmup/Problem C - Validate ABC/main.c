#include <stdio.h>      /* getchar_unlocked(), puts_unlocked() */

int
main(void)
{
    int T;          /* test cases (range: 1 - 1000) */
    int A, B, C;    /* inputs/operands (range: 0 - 9) */
    int ch;

    T = 0;
    while ((ch = getchar_unlocked()) != '\n')
        T = 10 * T + (ch ^ '0');

    for (; T; T--) {
        A = getchar_unlocked() ^ '0';
        (void)getchar_unlocked();   /* space */

        B = getchar_unlocked() ^ '0';
        (void)getchar_unlocked();   /* space */

        C = getchar_unlocked() ^ '0';
        (void)getchar_unlocked();   /* newline */

        if (A + B == C) {
            puts_unlocked("YES");
            continue;
        }

        if (A - B == C) {
            puts_unlocked("YES");
            continue;
        }

        if (A * B == C) {
            puts_unlocked("YES");
            continue;
        }

        /* avoid division by zero */
        if (B) {
            if (A / B == C) {
                puts_unlocked("YES");
                continue;
            }

            if (A % B == C) {
                puts_unlocked("YES");
                continue;
            }
        }

        puts_unlocked("NO");
    }

    return 0;
}
