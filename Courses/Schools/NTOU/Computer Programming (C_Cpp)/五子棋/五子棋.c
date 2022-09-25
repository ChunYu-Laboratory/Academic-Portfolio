#include <stdio.h>

int r_count( int , int [][19] );

int c_count( int , int [][19] );

int h_check( int , int , int [][19] );

int v_check( int , int , int [][19] );

int s_check( int , int , int [][19] );


int main()
{
    int x, y, m, n;
    int board[19][19] = { 0 };
    int status = 1;

    while ( scanf( "%d,%d", &y, &x ) != EOF )
    {
        board[y][x] = status;

        m = r_count( y, board );
        n = c_count( x, board );

        printf( "%d:%d %d:%d\n", y, m, x, n );

        if ( h_check( y, x, board ) )
        {
            break;
        }
        if ( v_check( y, x, board ) )
        {
            break;
        }
        if ( s_check( y, x, board ) )
        {
            break;
        }

        status = -status;
    }

    if ( status == 1 )
    {
        printf( "black\n" );
    }
    else
    {
        printf( "white\n" );
    }
}

int r_count( int y, int board[][19] )
{
    int i, m = 0;

    for ( i = 0; i < 19; i++ )
    {
        m += board[y][i] != 0 ? 1 : 0;
    }

    return m;
}

int c_count( int x, int board[][19] )
{
    int i, n = 0;

    for ( i = 0; i < 19; i++ )
    {
        n += board[i][x] != 0 ? 1 : 0;
    }

    return n;
}

int h_check( int r, int c, int board[][19] )
{
    int color = board[r][c];
    int i;
    int n = 1;

    for ( i = c + 1; i < 19; i++ )
    {
        if ( board[r][i] == color )
        {
            n++;
        }
        else
        {
            break;
        }
    }

    for ( i = c - 1; i >= 0; i-- )
    {
        if ( board[r][i] == color )
        {
            n++;
        }
        else
        {
            break;
        }
    }

    return n == 5 ? 1 : 0;
}

int v_check( int r, int c, int board[][19] )
{
    int color = board[r][c];
    int i;
    int n = 1;

    for ( i = r + 1; i < 19; i++ )
    {
        if ( board[i][c] == color )
        {
            n++;
        }
        else
        {
            break;
        }
    }

    for ( i = r - 1; i >= 0; i-- )
    {
        if ( board[i][c] == color )
        {
            n++;
        }
        else
        {
            break;
        }
    }

    return n == 5 ? 1 : 0;
}

int s_check( int r, int c, int board[][19] )
{
    int color = board[r][c];
    int i, j;
    int n = 1, m = 1;

    for ( i = r + 1, j = c + 1; i < 19 && j < 19; i++, j++ )
    {
        if ( board[i][j] == color )
        {
            n++;
        }
        else
        {
            break;
        }
    }

    for ( i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j-- )
    {
        if ( board[i][j] == color )
        {
            n++;
        }
        else
        {
            break;
        }
    }

    if ( n == 5 )
    {
        return 1;
    }

    for ( i = r + 1, j = c - 1; i < 19 && j >= 0; i++, j-- )
    {
        if ( board[i][j] == color )
        {
            m++;
        }
        else
        {
            break;
        }
    }

    for ( i = r - 1, j = c + 1; i >= 0 && j < 19; i--, j++ )
    {
        if ( board[i][j] == color )
        {
            m++;
        }
        else
        {
            break;
        }
    }

    return m == 5 ? 1 : 0;
}