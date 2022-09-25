#include <stdio.h>

typedef unsigned long long int ulli;

ulli min_d( ulli );

int main()
{
    long long int x, y;
    ulli X, Y, X_Y, D;

    while ( scanf("%lld %lld", &x, &y) != EOF )
    {
        X = x >= 0 ? x : -x;
        Y = y >= 0 ? y : -y;
        X_Y = X + Y;

        D = min_d( X_Y );

        printf( "%llu\n", D );
    }
}

ulli min_d( ulli X_Y )
{
    ulli f0 = 0, f1 = 1, f = 1, d1, d2;

    while ( X_Y >= f1 )
    {
        f0 = f1;
        f1 = f;
        f = f0 + f1;
    }

    d1 = X_Y - f0;
    d2 = f1 - X_Y;

    return d1 <= d2 ? d1 : d2;
}