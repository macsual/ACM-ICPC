#define MAX_OP_LEN 1 /* operation code */ + 1 /* space */                     \
                   + 6 /* i (i.e. range start [max: 10^5]) */ + 1 /* space */ \
                   + 6 /* j (i.e. range end [max: 10^5]) */ + 1 /* space */   \
                   + 102 /* m (max: 10^101) */

#include <stdio.h>      /* scanf, printf, sscanf */
#include <string.h>     /* memset, strchr */

int
main(void)
{
    int x;
    int N;      /* list size (range: 1 - 10^5) */
    int Q;      /* number of list operations (range: 1 - 10^4) */
    int i, j;   /* range bounds */
    char *p;
    int index, max_index;

    /*
     * List contains integers, however elements range from 1 - 10^101, so the
     * maximum is too large to be stored in any standard C integral type.
     * Furthermore, the input comes from a character stream anyway so we
     * benefit from no conversion overhead and we need to iterate over the
     * digits of the element in order to tally frequency.
     * 
     * The row size is explained as follows: 1 for leading 1 digit, 101 for
     * trailing 101 0's (zeroes) and the additional 1 for storage for the
     * terminating null character.
     */
    static char lst[100000][1 + 101 + 1];

    char m[1 + 101 + 1];

    /* extra 1 for null character */
    static char op_queue[10000][MAX_OP_LEN + 1];

    int digits_f[10];   /* frequency of each digit in the range of 0 to 9 */

    scanf("%d %d", &N, &Q);

    for (x = 0; x < N; x++)
        scanf("%s", lst[x]);

    /*
     * consume newline character left over from last call to scanf() so that
     * fgets() does not read an empty line and return
     */
    (void)getchar();

    for (x = 0; x < Q; x++) {
        (void)fgets(op_queue[x], sizeof op_queue[x], stdin);
        p = strchr(op_queue[x], '\n');
        if (p)
            *p = '\0';
    }

    for (x = 0; x < Q; x++) {
        if (op_queue[x][0] == '0') {
            sscanf(op_queue[x], "%*d %d %d", &i, &j);

            (void)memset(digits_f, 0, sizeof digits_f);

            /* the range bounds are not given to us zero-indexed */
            for (i = i - 1; i < j; i++) {
                p = lst[i];
                while (*p) {    /* null character has an integer value of 0 */
                    index = *p - '0';
                    digits_f[index]++;
                    p++;
                }
            }

            max_index = 0;
            for (index = 1; index < 9; index++) {
                if (digits_f[index] > digits_f[max_index])
                    max_index = index;
            }

            printf("%d\n", max_index);
        } else {    /* op_queue[i][0] == '1' */
            sscanf(op_queue[x], "%*d %d %d %s", &i, &j, m);

            /* the range bounds are not given to us zero-indexed */
            for (i = i - 1; i < j; i++)
                snprintf(lst[i], sizeof lst[i], "%s", m);
        }
    }

    return 0;
}
