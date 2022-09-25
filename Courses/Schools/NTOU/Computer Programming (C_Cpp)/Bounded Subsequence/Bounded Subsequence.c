#include <stdio.h>

int main()
{
    int n = 0;
    int i, j, k;
    int len, max_len, max, min;
    int a[1000];
    char c;

    while ( scanf( "%d", &a[n] ) != EOF )
    {
        n++;

        scanf( "%c", &c );

        if ( c == '\n')
        {
            max_len = 1;

            for ( i = 0; i < n; i++ )
            {
                for ( j = i + 1; j < n; j++ )
                {
                    if ( a[i] > a[j] )
                    {
                        max = a[i];
                        min = a[j];
                    }
                    else
                    {
                        max = a[j];
                        min = a[i];
                    }

                    for ( k = i + 1; k < j; k++ )
                    {
                        if ( a[k] < min || a[k] > max )
                        {
                            break;
                        }
                    }

                    if ( k == j ) /* the subsequence between i and j is a bounded subsequence. */
                    {
                        len = j - i + 1; /* the length of this bounded subseqnece is j-i+1 */

                        if ( len > max_len )
                        {
                            max_len = len;
                        }
                    }
                }
            }

            printf( "%d\n", max_len );

            n = 0;
        }
    }
}