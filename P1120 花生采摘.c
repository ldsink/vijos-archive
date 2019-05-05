#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {
    int M, N, K, i, j, k, x, y, m, n = 0, f = 0, x0, y0, p = 0;
    int a[21][21] = {0};
    scanf("%d%d%d", &M, &N, &K);
    for (i = 0; i < M; i++)
        for (j = 0; j < N; j++)
            scanf("%d", &a[i][j]);
    for (k = 0; k < M * N; k++) {
        m = 0;
        for (i = 0; i < M; i++)
            for (j = 0; j < N; j++)
                if (a[i][j] > m) {
                    x = j;
                    y = i;
                    m = a[i][j];
                }
        if (f == 0 && K > 2 * (y + 1)) {
            K -= 2;
            K -= y;
            p += a[y][x];
            a[y][x] = 0;
            f = 1;
            x0 = x;
            y0 = y;
            continue;
        }
        if (f == 1 && (abs(y - y0) + y + 2 + abs(x - x0)) <= K) {
            K -= abs(x0 - x);
            K -= abs(y0 - y);
            K--;
            p += a[y][x];
            a[y][x] = 0;
            x0 = x;
            y0 = y;
        }

    }
    printf("%d", p);
    return (0);
}
