//        n
//      _____
//      \    '
//       \                  4*k
//        \        k + 1 /x\
//         \   (-1)     *|-|
//         /             \3/
//        /    ----------------
//       /          (2*k)!!
//      /____,
//      k = 0

#include <stdio.h>

int main()
{
    int k = 1, n;               //
    float x;                    // Declaring variables
    long double l = -1, s = 0;  //

    printf("Please, enter your X and N.\n");

    scanf("%f %d", &x, &n);

    x = x / 3;  //
    x = x * x;  // Calculating (x/3)^(4k) 
    x = x * x;  //

    if (x != 0)                         //
    {                                   //
        s = -1;                         //
        while (k <= n)                  // 
        {                               // 
            l = (-l) * x / (k + k);     // Calculating sequence term
            s = s + l;                  //
            k++;                        //
        }                               //
    }                                   //

    printf("The answer: %.100Lf \nTo stop the programm use key interaption.\n", s);

    main();
    return 0;
}
