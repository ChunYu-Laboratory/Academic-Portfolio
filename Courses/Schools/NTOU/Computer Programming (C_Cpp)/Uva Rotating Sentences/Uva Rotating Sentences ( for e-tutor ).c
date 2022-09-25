#include <stdio.h>
#include <string.h>

int main()
{
    int N = 0, max_len = 0;
    int i, j;
    char sentence[100][101];
    char *loc;
    int len[100];

    while ( gets( sentence[N] ) )
    {
        N++;
    }

    for ( i = 0; i < N; i++ )
    {
        loc = sentence[i];

        while ( *loc != '\r' )
        {
            loc++;
        }

        *loc = '\0';
    }

    for ( i = 0; i < N; i++ )
    {
        len[i] = strlen( sentence[i] );

        if ( len[i] > max_len )
        {
            max_len = len[i];
        }
    }

    for ( i = 0; i < max_len; i++ )
    {
        for ( j = N-1; j >= 0; j-- )
        {
            if ( i < len[j] )
            {
                printf( "%c", sentence[j][i] );
            }
            else
            {
                printf( " " );
            }
        }

        printf( "\n" );
    }
}