#include <stdio.h>

#define SIZE 10

/* set the value for the ith bit */
void setbit( unsigned char [], int , int , int );

/* get the value of the ith bit */
int getbit( const unsigned char [], int , int );

int main()
{
    int i, v;
    unsigned char bitstreams[SIZE] = {0};

    scanf( "%d%d", &i, &v );

    while ( i != -1 )
    {
        setbit( bitstreams, SIZE, i, v );
        scanf( "%d%d", &i, &v );
    }

    for ( i = 0; i < SIZE; i++ )
    {
        printf( "%02x", bitstreams[i] );
    }

    printf( "\n" );

    scanf( "%d", &i );

    while ( i != -1 )
    {
        printf( "%d\n", getbit( bitstreams, SIZE, i ) );
        scanf( "%d", &i );
    }
}

void setbit( unsigned char bitstream[], int size, int i, int value )
{
    unsigned int n = i / 8;
    unsigned int shift = i & 7;
    unsigned char mask = 1 << shift;

    if ( value )
    {
        bitstream[n] |= mask;
    }
    else
    {
        bitstream[n] &= ~mask;
    }
}

int getbit( const unsigned char bitstream[], int size, int i )
{
    unsigned int n = i / 8;
    unsigned int shift = i & 7;
    unsigned char mask = 1 << shift;
    unsigned char bit = bitstream[n] & mask;
    bit >>= shift;

    return bit;
}