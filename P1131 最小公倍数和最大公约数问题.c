#include <stdio.h>

int Fun1(int a, int b) {
    if (b == 0)
        return a;
    else
        return Fun1(b, a % b);
}

int Fun2(int a, int b) {
    if (Fun1(a, b) == 1)
        return 1;
    else
        return 0;
}

int main() {
    long x0, y0, i, j, k, total;
    scanf("%ld %ld", &x0, &y0);
    if (y0 % x0 != 0 || x0 == y0) {
        (x0 == y0) ?
        printf("1") : printf("0");
        return 0;
    }
    k = y0 / x0;
    j = (int) sqrt((double) k);
    for (i = 1, total = 0; i <= j; i++)
        if (k % i == 0 && Fun2(i, k / i))
            total++;
    printf("%ld", total * 2);
    return 0;
}
