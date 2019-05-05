#include<stdio.h>

int main() {
    int k;
    double sum;
    long i;
    scanf("%d", &k);
    for (i = 1, sum = 0; sum <= k; i++)
        sum += 1.0 / i;
    printf("%d", i - 1);
    return (0);
}
