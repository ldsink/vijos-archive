/*
Author ZHOU Cheng
Date 2010-3-14
Hungarian Algorithm
*/

#include <stdio.h>

int M, N, T, Ans, Link[101][101], Back[101], Come[101];

int Find(int people) {
    int a, b, c;
    a = Back[people];
    b = 0;
    for (c = people + 1; c <= N; c++)
        if (Link[a][c] && (Back[c] == 0 || Find(c))) {
            Come[a] = c + M;
            Back[c] = a;
            b = 1;
            break;
        }
    return b;
}

int main() {
    freopen("Hungarian Algorithm.in", "r", stdin);
    freopen("Hungarian Algorithm.out", "w", stdout);
    scanf("%d %d", &M, &N);
    int a, b;
    scanf("%d %d", &a, &b);
    while (a != -1) {
        b -= M;
        Link[a][b] = 1;
        scanf("%d %d", &a, &b);
    }
    for (a = 1; a <= M; a++)
        for (b = 1; b <= N; b++)
            if (Link[a][b] && (Back[b] == 0 || Find(b))) {
                Come[a] = b + M;
                Back[b] = a;
                Ans++;
                break;
            }
    if (Ans > 0) printf("%d\n", Ans);
    else printf("No Solution!");
    return 0;
}
