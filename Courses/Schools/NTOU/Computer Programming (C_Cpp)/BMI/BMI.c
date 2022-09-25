#include <stdio.h>

int main()
{
    float BMI, weight, height;

    scanf("%f", &weight);
    scanf("%f", &height);

    BMI = weight/(height*height);

    printf("%.2f\n", BMI);
}