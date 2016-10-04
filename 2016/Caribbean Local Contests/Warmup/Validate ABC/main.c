#include <stdio.h>      /* scanf(), puts() */
#include <stdlib.h>     /* EXIT_SUCCESS */

int
main(void)
{
    int i;
    int T;          /* test cases (range: 1 - 1000) */
    int A, B, C;    /* inputs/operands (range: 0 - 9) */

    scanf("%d", &T);

    for (i = 0; i < T; i++) {
        scanf("%d %d %d", &A, &B, &C);

        if (A + B == C) {
            puts("YES");
            continue;
        }

        if (A - B == C) {
            puts("YES");
            continue;
        }

        if (A * B == C) {
            puts("YES");
            continue;
        }

        /* avoid division by zero */
        if (B) {
            if (A / B == C) {
                puts("YES");
                continue;
            }

            if (A % B == C) {
                puts("YES");
                continue;
            }
        }

        puts("NO");
    }

    return EXIT_SUCCESS;
}
