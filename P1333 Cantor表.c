#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main() {
    int N, i1, i2, n, he, x, y;
    scanf("%d", &N);
    for (i1 = 1, he = 0; he < N; i1++)
        he += i1;
    i1--;
    he -= i1;
    if (i1 % 2 == 0) {
        for (i2 = 0; he < N; i2++, i1--)
            he++;
        i1++;
    } else if (i1 % 2 == 1) {
        for (i2 = i1, i1 = 0; he < N; i2--, i1++)
            he++;
        i2++;
    }
    printf("%d/%d", i2, i1);
    return (0);
}
