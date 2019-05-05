#include<stdio.h>

int m, n, d[31][31];

int f(long p, long t);

int main() {
    int count, i, j;
    for (i = 0; i < 31; i++)
        for (j = 0; j < 31; j++)
            d[i][j] = -1;
    scanf("%d %d", &n, &m);
    count = f(1, 0);
    printf("%d", count);
    return 0;
}

int f(long p, long t) {
    int k, l;
    if (d[p][t] == -1) {
        if (t == m) {
            if (p == 1)
                d[p][t] = 1;
            else
                d[p][t] = 0;
        } else {
            k = p + 1;
            l = p - 1;
            if (k > n)
                k = 1;
            if (l < 1)
                l = n;
            d[p][t] = f(k, t + 1) + f(l, t + 1);
        }
    }
    return d[p][t];
}
