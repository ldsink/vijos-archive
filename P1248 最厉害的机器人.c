#include<stdio.h>

int K, Re[41][10][10][10][10];
double Ans, X1, X2, X3, X4;

void Find(int money, int a, int b, int c, int d) {
    if (money > 0 && Re[money][a][b][c][d] == 0) {
        Re[money][a][b][c][d] = 1;
        if (a < 10)
            Find(money - 1, a + 1, b, c, d);
        if (b < 10)
            Find(money - 1, a, b + 1, c, d);
        if (c < 10)
            Find(money - 1, a, b, c + 1, d);
        if (d < 10)
            Find(money - 1, a, b, c, d + 1);
    } else {
        double temp;
        temp = (20 - a * 2) * X1 + (2 * (100 - b * 7) * X2 + (100 - c * 9.0) * X3) / ((10 + d * 1.0) * X4);
        Ans = Ans > temp ? temp : Ans;
    }
}

int main() {
    scanf("%d %lf %lf %lf %lf", &K, &X1, &X2, &X3, &X4);
    Ans = 1000000000;
    Find(K, 0, 0, 0, 0);
    printf("%.3lf", Ans);
    return 0;
}
