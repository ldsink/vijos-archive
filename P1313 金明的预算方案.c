#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

int Max(int a, int b) {
    if (a < b) a = b;
    return (a);
}

int N, n, i, j, k, count_z, money;
int price[61][10], worth[61][10], v[61], p[61], q[61], re[3300];

int main() {
    scanf("%d %d", &N, &n);
    N /= 10;
    for (i = 1; i <= n; i++) {
        scanf("%d %d %d", &k, &p[i], &q[i]);
        v[i] = k / 10;
    }
    for (count_z = 1, i = 1; i <= n; i++)
        if (q[i] == 0) {
            price[count_z][1] = price[count_z][2] = price[count_z][3] = price[count_z][4] = v[i];
            worth[count_z][1] = worth[count_z][2] = worth[count_z][3] = worth[count_z][4] = p[i] * v[i];
            for (j = 1, k = 2; j <= n; j++) {
                if (q[j] == i) {
                    price[count_z][k] += v[j];
                    price[count_z][4] += v[j];
                    worth[count_z][k] += v[j] * p[j];
                    worth[count_z][4] += v[j] * p[j];
                    k++;
                }
            }
            count_z++;
        }
    for (i = 1; i < count_z; i++)
        for (money = N; money > 0; money--)
            for (k = 1; k < 5; k++)
                if (money - price[i][k] >= 0)
                    re[money] = Max(re[money], re[money - price[i][k]] + worth[i][k]);
    printf("%d", re[N] * 10);
    return (0);
}
