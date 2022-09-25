#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    float x, y;
} point;

int compare( const void * , const void * );

int main()
{
    int i, n;
    point p[100];

    scanf( "%d", &n );

    for ( i = 0; i < n; i++ )
    {
        scanf( "%f %f", &p[i].x , &p[i].y );
    }

    qsort( p, n, sizeof(point), compare );

    for ( i = 0; i < n; i++ )
    {
        printf( "%.2f %.2f\n", p[i].x , p[i].y );
    }
}

int compare( const void *a, const void *b )
{
    const point *i = (const point*) a;
    const point *j = (const point*) b;

    if ( i->x != j->x )
    {
        return i->x < j->x ? -1 : 1;
    }
    else
    {
        return i->y < j->y ? -1 : 1;
    }
}