#include<stdio.h>
#include<stdlib.h>
#include<string.h>

long R, C, Result, site[502][502], map[502][502];

long Max(long a, long b);

long Work(long i, long j);

int main() {
    long w, h, v;
    scanf("%d %d", &R, &C);
    for (h = 1; h <= R; h++)
        for (w = 1; w <= C; w++)
            scanf("%ld", &site[h][w]);
    for (h = 1; h <= R; h++)
        site[h][0] = site[h][C + 1] = 100000;
    for (w = 1; w <= C; w++)
        site[0][w] = site[R + 1][w] = 100000;
    memset(map, 0, sizeof(map));
    Result = 1;
    for (h = 1; h <= R; h++)
        for (w = 1; w <= C; w++)
            if (map[h][w] == 0) {
                v = Work(h, w);
                Result = Max(Result, v);
            }
    printf("%ld", Result);
    return 0;
}

long Max(long a, long b) {
    if (a < b)
        a = b;
    return a;
}

long Work(long i, long j) {
    if (map[i][j] == 0) {
        if (site[i + 1][j] < site[i][j])
            map[i][j] = Max(Work(i + 1, j), map[i][j]);
        if (site[i][j + 1] < site[i][j])
            map[i][j] = Max(Work(i, j + 1), map[i][j]);
        if (site[i - 1][j] < site[i][j])
            map[i][j] = Max(Work(i - 1, j), map[i][j]);
        if (site[i][j - 1] < site[i][j])
            map[i][j] = Max(Work(i, j - 1), map[i][j]);
        map[i][j]++;
    }
    return map[i][j];
}
