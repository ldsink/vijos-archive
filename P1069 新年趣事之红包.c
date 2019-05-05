#include<stdio.h>

int N;
double Ans, Site[800][2], Dis[800][800], Re[800][800][2];

double Search(int q, int h, int c) {
    int a, b;
    a = q + 1;
    if (a == N) a = 0;
    if (a == h)
        return 0;
    else if (Re[q][h][c] != 0)
        return Re[q][h][c];
    else {
        double l1, l2;
        a = q + 1;
        b = h - 1;
        if (a == N) a = 0;
        if (b == -1) b = N - 1;
        if (c == 0) {
            l1 = Dis[q][a];
            l1 += Search(a, h, 0);
            l2 = Dis[q][b];
            l2 += Search(q, b, 1);
            Re[q][h][c] = l1 > l2 ? l2 : l1;
        } else {
            l1 = Dis[h][a];
            l1 += Search(a, h, 0);
            l2 = Dis[h][b];
            l2 += Search(q, b, 1);
            Re[q][h][c] = l1 > l2 ? l2 : l1;
        }
        return Re[q][h][c];
    }
}

int main() {
    scanf("%d", &N);
    int a, b, q, h;
    double temp;
    for (a = 0; a < N; a++)
        scanf("%lf %lf", &Site[a][0], &Site[a][1]);
    for (a = 0; a < N; a++)
        for (b = a + 1; b < N; b++) {
            Dis[a][b] = (Site[a][0] - Site[b][0]) * (Site[a][0] - Site[b][0]);
            Dis[a][b] += (Site[a][1] - Site[b][1]) * (Site[a][1] - Site[b][1]);
            Dis[a][b] = sqrt(Dis[a][b]);
            Dis[b][a] = Dis[a][b];
        }
    for (a = 0, Ans = 1000000000; a < N; a++) {
        q = a;
        h = a - 1;
        if (h == -1) h = N - 1;
        temp = Dis[q][h];
        temp += Search(q, h, 0);
        if (Ans > temp)
            Ans = temp;
        temp = Dis[q][h];
        temp += Search(q, h, 1);
        if (Ans > temp)
            Ans = temp;
    }
    printf("%.3lf\n", Ans);
    return 0;
}
