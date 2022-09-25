#include <stdio.h>
#include <stdlib.h>

int isOdd( int );

int compare( const void * , const void * );

int N, M;

int main()
{
    int data[10000];
    int i, end;

    while ( scanf( "%d %d", &N, &M ) != EOF )
    {
        for ( i = 0; i < N; i++ )
        {
            scanf( "%d", &data[i] );
        }

        scanf( "%d %d", &end, &end );
        
        printf( "%d %d\n", N, M );

        qsort( data, N, sizeof(int), compare );

        for ( i = 0; i < N; i++ )
        {
            printf( "%d\n", data[i] );
        }

        printf( "%d %d\n", 0, 0 );
    }
}

int isOdd( int num )
{
    return num & 1;
}

int compare( const void *a, const void *b )
{
    int x = *( (const int*) a );
    int y = *( (const int*) b );

    int xM = x % M;
    int yM = y % M;

    if ( xM != yM )
    {
        return xM < yM ? -1 : 1;
    }
    else if ( isOdd( x ) != isOdd( y ) )
    {
        return isOdd( x ) ? -1 : 1;
    }
    else if ( isOdd( x ) )
    {
        return x >= y ? -1 : 1;
    }
    else
    {
        return x <= y ? -1 : 1;
    }
}