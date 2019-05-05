#include<stdio.h>

int N, Num[20][20], Re[21][21][21][41];

void Search(int xa, int xb, int xc, int step) {
    if (Re[xa][xb][xc][step] == 0) {
        int ya, yb, yc;
        ya = step - xa - 1;
        yb = step - xb - 1;
        yc = step - xc - 1;
        if (xa < N && xb < N && xc < N && ya < N && yb < N && yc < N) {
            Re[xa][xb][xc][step] += Num[xa][ya];
            if (xb != xa) Re[xa][xb][xc][step] += Num[xb][yb];
            if (xc != xa && xc != xb) Re[xa][xb][xc][step] += Num[xc][yc];
            int temp = 0;
            Search(xa + 1, xb + 1, xc + 1, step + 1);
            if (temp < Re[xa + 1][xb + 1][xc + 1][step + 1])
                temp = Re[xa + 1][xb + 1][xc + 1][step + 1];
            Search(xa + 1, xb + 1, xc, step + 1);
            if (temp < Re[xa + 1][xb + 1][xc][step + 1])
                temp = Re[xa + 1][xb + 1][xc][step + 1];
            Search(xa + 1, xb, xc + 1, step + 1);
            if (temp < Re[xa + 1][xb][xc + 1][step + 1])
                temp = Re[xa + 1][xb][xc + 1][step + 1];
            Search(xa, xb + 1, xc + 1, step + 1);
            if (temp < Re[xa][xb + 1][xc + 1][step + 1])
                temp = Re[xa][xb + 1][xc + 1][step + 1];
            Search(xa, xb, xc + 1, step + 1);
            if (temp < Re[xa][xb][xc + 1][step + 1])
                temp = Re[xa][xb][xc + 1][step + 1];
            Search(xa, xb + 1, xc, step + 1);
            if (temp < Re[xa][xb + 1][xc][step + 1])
                temp = Re[xa][xb + 1][xc][step + 1];
            Search(xa + 1, xb, xc, step + 1);
            if (temp < Re[xa + 1][xb][xc][step + 1])
                temp = Re[xa + 1][xb][xc][step + 1];
            Search(xa, xb, xc, step + 1);
            if (temp < Re[xa][xb][xc][step + 1])
                temp = Re[xa][xb][xc][step + 1];
            Re[xa][xb][xc][step] += temp;
        }
    }
}

int main() {
    int a, b;
    scanf("%d", &N);
    for (a = 0; a < N; a++)
        for (b = 0; b < N; b++)
            scanf("%d", &Num[a][b]);
    Search(0, 0, 0, 1);
    printf("%d\n", Re[0][0][0][1]);
    return 0;
}
