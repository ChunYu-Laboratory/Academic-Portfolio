#include <stdio.h>

int main()
{
    int t, i;

    scanf("%d", &t);

    for (i = 0; i < t; i++)
    {
        int n, s = 0, x, x_square;

        scanf("%d", &n);

        for (x = 1, x_square = 1; x_square <= n; x++, x_square = x*x)
        {
            if (n % x == 0)
            {
                s += x_square < n ? x + n/x : x;
            }
        }

        s -= n;

        if (s < n)
        {
            printf("%s\n", "deficient");
        }
        else if (s == n)
        {
            printf("%s\n", "perfect");
        }
        else
        {
            printf("%s\n", "abundant");
        }
    }
}