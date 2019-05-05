#include<stdio.h>

int main() {
    long M, n = 0;
    scanf("%ld", &M);
    while ((1 + n * n) / 2 <= M)
        n++;
    for (n--; n >= 2; n--)
        if ((2 * M - n * n - n) % (2 * n) == 0)
            printf("%d %d\n", (2 * M + 1 - n * n) / (2 * n) + 1, ((2 * M + 1 - n * n) / (2 * n)) + n);
    return 0;
} 
