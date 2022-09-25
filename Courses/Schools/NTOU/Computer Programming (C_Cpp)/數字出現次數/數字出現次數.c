#include <stdio.h>

int main()
{
    int N, a, b, n, i, k, appear[100] = {0};

    scanf("%d %d %d", &N, &a, &b);

    for (k = 0; k < N; k++)
    {
        scanf("%d", &n);

        appear[n-a]++;
    }

    for (i = a; i <= b; i++)
    {
        printf("%d appears %d times\n", i, appear[i-a]);
    }
}