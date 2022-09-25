#include <stdio.h>
#include <stdlib.h>

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int max_index(int arr[], int size)
{
    int i, max_id;

    for (max_id = 1, i = 3; i < size*2; i += 2)
    {
        if (arr[i] > arr[max_id])
        {
            max_id = i;
        }
    }

    return max_id;
}

void count(int *num, int *num_times, int size)
{
    int i, j, times;

    for (i = 1, j = 0, times = 1; i < size; i++)
    {
        if (num[i] == num[i-1])
        {
            times++;
        }
        else
        {
            num_times[j] = num[i-1];
            num_times[j+1] = times;

            j += 2;
            times = 1;
        }
    }
}

int main()
{
    int N, a, b, i, max_times, max_id;
    int num[1000], num_times[2000] = {0};

    scanf("%d %d %d", &N, &a, &b);

    for (i = 0; i < N; i++)
    {
        scanf("%d", &num[i]);
    }

    qsort (num, N, sizeof(int), compare);
    count(num, num_times, N);
    max_id = max_index(num_times, N);
    max_times = num_times[max_id];

    for (i = 1; i < 2*N; i += 2)
    {
        if (num_times[i] == max_times)
        {
            printf("%d appears %d times\n", num_times[i-1], max_times);
        }
    }
}