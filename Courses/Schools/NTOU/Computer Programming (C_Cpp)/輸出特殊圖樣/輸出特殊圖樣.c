#include <stdio.h>

int main()
{
    int n, m, i, j, status;

    scanf( "%d", &n );

    m = 2*n - 1;

    for ( i = 0, status = 0; i < m; i++, status = i & 1 ? 1 : 0 )
    {
        for ( j = 0; j < (i+1); j++ )
        {
            if ( status )
                printf( "%c", 'X' );
            else
                printf( "%c", 'A' );
        }

        for ( j = 0; j < (m-i-1); j++ )
        {
            if ( status == 0 )
            {
                printf( "%c", 'X' );

                status = 1;
            }
            else
            {
                printf( "%c", 'A' );

                status = 0;
            }
        }

        printf( "\n" );
    }
}