#include <stdio.h>      /* scanf(), printf() */
#include <stdlib.h>     /* EXIT_SUCCESS */

int
main(void)
{
    int A, B;   /* inputs (range: 0 - 10) */

    scanf("%d %d", &A, &B);

    printf("%d\n", A + B);

    return EXIT_SUCCESS;
}
