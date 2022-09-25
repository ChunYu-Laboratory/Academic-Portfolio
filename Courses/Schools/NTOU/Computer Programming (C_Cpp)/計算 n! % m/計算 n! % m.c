#include <stdio.h>

int main()
{
    int m, n, k, i, j;

    scanf("%d", &k);

    for (i = 0; i < k; i++)
    {
        int x = 1;

        scanf("%d %d", &n, &m);

        for (j = n; j > 0; j--)
        {
            x *= j;
        }

        printf("%d\n", x % m);
    }
}