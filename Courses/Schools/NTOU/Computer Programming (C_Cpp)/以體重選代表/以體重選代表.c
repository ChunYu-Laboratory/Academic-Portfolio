#include <stdio.h>

float mean ( const int [], int, int );

int divide ( const int [], int, int, int );

int main()
{
    int n, i, a[1000], index;

    scanf( "%d", &n );

    for ( i = 0; i < n; i++ )
    {
        scanf( "%d", &a[i] );
    }

    index = divide( a, 0, n/2-1, n );

    printf( "%d\n", index );
}

float mean ( const int a[], int start, int end )
{
    int sum = 0, avg, i, size;

    size = end - start;

    for ( i = start; i < end; i++ )
    {
        sum += a[i];
    }

    avg = (float) sum / size;

    return avg;
}

int divide ( const int a[], int low, int mid, int high )
{
    int w1, w2;

    if ( (high - low) == 1 )
        return low;

    w1 = mean( a, low, mid+1 );
    w2 = mean( a, mid+1, high );

    if ( w1 >= w2 )
    {
        high = mid + 1;
        mid = (high + low) / 2 - 1;
        divide( a, low, mid, high );
    }
    else
    {
        low = mid + 1;
        mid = (high + low) / 2 - 1;
        divide( a, low, mid, high );
    }
}