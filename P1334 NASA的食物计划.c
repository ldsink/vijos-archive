#include<stdio.h>

int V, M, N, T[50], Z[50], K[50], Re[401][401][50];

int Fun(int v, int m, int t) {
    if (t == N)
        return 0;
    if (Re[v][m][t] == 0) {
        int a = 0, b = 0;
        if (v >= T[t] && m >= Z[t]) {
            a = K[t];
            a += Fun(v - T[t], m - Z[t], t + 1);
        }
        b = Fun(v, m, t + 1);
        Re[v][m][t] = a > b ? a : b;
    }
    return Re[v][m][t];
}

int main() {
    scanf("%d %d", &V, &M);
    scanf("%d", &N);
    int a;
    for (a = 0; a < N; a++)
        scanf("%d %d %d", &T[a], &Z[a], &K[a]);
    Re[V][M][0] = Fun(V, M, 0);
    printf("%d\n", Re[V][M][0]);
    return 0;
}
