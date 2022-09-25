#include <stdio.h>
#include <math.h>

int main()
{
    int n;

    while (scanf("%d", &n) != EOF)
    {
        int x[9], y[9], i, s = 0;

        for (i = 0; i < n; i++)
        {
            scanf("%1d", &x[i]);
        }

        for (i = 0; i < n; i++)
        {
            scanf("%1d", &y[i]);
        }

        for (i = 0; i < n; i++)
        {
            if (abs(x[i] - y[i]) > 5)
            {
                s += x[i] < y[i] ? abs(x[i] - y[i] + 10) : abs(x[i] - y[i] - 10);
            }
            else
            {
                s += abs(x[i] - y[i]);
            }
        }

        printf("%d\n", s);
    }
}