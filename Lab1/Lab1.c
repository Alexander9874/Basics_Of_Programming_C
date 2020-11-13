#include <stdio.h>

int main() {
    double a;
    int p = 0;
    printf("Hello! Please, enter the value:\n");
    scanf("%lf", &a);

    while (!((a < 10 && a >= 1) || (a > -10 && a <= -1) || (a == 0)))
    {
        if (a > -1 && a < 1)
        {
            a = a * 10;
            p--;
        }
        else
        {
            a = a / 10;
            p++;
        }
    }

    printf("The number in exponential form:\n");
    printf("%lfE10^%d\n", a, p);
    printf("Exponent=%d\n", p);
    printf("Would you like to continue? (Yes/No) [1/anything another]\n");
    scanf("%d", &p);

    if (p == 1)
    {
        main();
    }
    return 0;
}
