#include<stdio.h>

int f(int, int);

typedef struct node {
    int z;
    int c;
    int v;
} cixiu;
cixiu a[3];
int v[101], z[101], c[101], n, m, F[101][8010];

int main() {
    int i, b[101], j;
    scanf("%d%d", &n, &m);
    for (i = 0; i < 3; i++)
        scanf("%d%d%d", &a[i].z, &a[i].c, &a[i].v);
    for (i = 0; i < n; i++)
        scanf("%d%d", &b[i], &z[i]);
    for (i = 0; i < n; i++) {
        for (j = 0; j < 3; j++)
            if (z[i] == a[j].z) {
                v[i] = b[i] + b[i] * a[j].v;
                c[i] = b[i] * a[j].c;
            }
    }
    printf("%d", f(0, m));
    return 0;
}

int f(int i, int j) {
    int p, q;
    if (F[i][j] == 0) {
        if (i == n || j == 0)
            F[i][j] = 0;
        else {
            p = 0;
            q = 0;
            p = f(i + 1, j);
            if (j - v[i] >= 0)
                q = f(i + 1, j - v[i]) + c[i];
            if (p > q)
                F[i][j] = p;
            else
                F[i][j] = q;
        }
    }
    return F[i][j];
}
