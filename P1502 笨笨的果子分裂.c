#include<stdio.h>

double a[35][35][35], b[35][35][35];
int o, m, n, i, j;

int main() {
    scanf("%d %d %d", &o, &n, &m);
    a[1][1][m] = 1;
    for (i = 1; i <= o; i++) {
        b[1][1][1] = a[1][1][1];
        b[1][n][n] = a[1][n][n];
        b[1][n][1] = a[1][n][1];
        b[n][1][1] = a[n][1][1];
        b[n][n][1] = a[n][n][1];
        b[n][1][n] = a[n][1][n];
        b[1][1][n] = a[1][1][n];
        b[n][n][n] = a[n][n][n];
        for (j = 2; j <= n - 1; j++) {
            b[1][j][1] = a[1][j][1];
            b[1][1][j] = a[1][1][j];
            b[1][n][j] = a[1][n][j];
            b[n][1][j] = a[n][1][j];
            b[1][j][n] = a[1][j][n];
            b[n][n][j] = a[n][n][j];
            b[j][1][1] = a[j][1][1];
            b[j][n][n] = a[j][n][n];
            b[j][n][1] = a[j][n][1];
            b[j][1][n] = a[j][1][n];
            b[n][j][1] = a[n][j][1];
            b[n][j][n] = a[n][j][n];
        }
        a[1][1][1] = b[1][1][2] + b[1][2][1] + b[2][1][1];
        a[1][1][n] = b[1][1][n - 1] + b[1][2][n] + b[2][1][n];
        a[1][n][1] = b[1][n - 1][1] + b[1][n][2] + b[2][n][1];
        a[1][n][n] = b[1][n][n - 1] + b[1][n - 1][n] + b[2][n][n];
        a[n][1][1] = b[n - 1][1][1] + b[n][1][2] + b[n][2][1];
        a[n][n][1] = b[n][n - 1][1] + b[n - 1][n][1] + b[n][n][2];
        a[n][n][n] = b[n][n][n - 1] + b[n][n - 1][n] + b[n - 1][n][n];
        a[n][1][n] = b[n][1][n - 1] + b[n - 1][1][n] + b[n][2][n];
        for (j = 2; j <= n - 1; j++) {
            a[1][j][1] = b[1][j - 1][1] + b[1][j + 1][1];
            a[1][1][j] = b[1][1][j - 1] + b[1][1][j + 1];
            a[1][j][n] = b[1][j - 1][n] + b[1][j + 1][n];
            a[n][j][1] = b[n][j - 1][1] + b[n][j + 1][1];
            a[n][j][n] = b[n][j - 1][n] + b[n][j + 1][n];
            a[1][n][j] = b[1][n][j - 1] + b[1][n][j + 1];
            a[n][1][j] = b[n][1][j - 1] + b[n][1][j + 1];
            a[n][n][j] = b[n][n][j - 1] + b[n][n][j + 1];
            a[j][1][1] = b[j - 1][1][1] + b[j + 1][1][1];
            a[j][n][1] = b[j - 1][n][1] + b[j + 1][n][1];
            a[j][1][n] = b[j - 1][1][n] + b[j + 1][1][n];
            a[j][n][n] = b[j - 1][n][n] + b[j + 1][n][n];
        }
    }
    printf("%.0lf\n", a[1][1][m]);
    return 0;
}
