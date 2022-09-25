#include <stdio.h>

int main()
{
    int a, b;

    while (scanf("%d %d", &a, &b) != EOF)
    {
        int n, x;

        for (n = a; n <= b; n++)
        {
            int s = 0, x_square;

            for (x = 1, x_square = 1; x_square <= n; x++, x_square = x*x)
            {
                if (n % x == 0)
                {
                    s += x_square < n ? x + n/x : x;
                }
            }

            if (s == 2*n)
            {
                printf("%d\n", n);
            }
        }
    }
}