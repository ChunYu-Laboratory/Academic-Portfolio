#include <stdio.h>

int main()
{
    int r, c;
    int i, j;
    int a[100][100], b[100][100];

    scanf("%d%d", &r, &c);

    for ( i = 0; i < r; i++ )
    {
        for ( j = 0; j < c; j++ )
        {
            scanf("%d", &a[i][j]);
        }
    }

    for ( i = 0; i < r; i++ )
    {
        for ( j = 0; j < c; j++ )
        {
            b[j][i] = a[i][j];
        }
    }

    for ( i = 0; i < r; i++ )
    {
        for ( j = 0; j < c; j++ )
        {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }

printf("\n");
system("pause");

}
