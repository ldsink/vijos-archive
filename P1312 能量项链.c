#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int n;
int energy[101][2], re[101][101];

int Max(int q, int h);

int main() {
    scanf("%d", &n);
    int i, j, max;
    scanf("%d", &energy[1][0]);
    for (i = 2; i <= n; i++) {
        scanf("%d", &energy[i][0]);
        energy[i - 1][1] = energy[i][0];
    }
    energy[n][1] = energy[1][0];
    for (max = 0, i = 1; i <= n; i++) {
        j = Max(i, i - 1);
        if (max < j)
            max = j;
    }
    printf("%d", max);
    return (0);
}

int Max(int q, int h) {
    if (h < 1) h = n;
    if (h > n) h = 1;
    if (q < 1) q = n;
    if (q > n) q = 1;
    if (h == q)
        return (0);
    else if (re[q][h] == 0) {
        int i, j, max;
        for (max = 0, i = q; i != h;) {
            j = energy[q][0] * energy[i][1] * energy[h][1];
            j += Max(q, i) + Max(i + 1, h);
            if (max < j)
                max = j;
            i++;
            if (i > n)
                i = 1;
        }
        re[q][h] = max;
        return (re[q][h]);
    } else
        return (re[q][h]);
}
