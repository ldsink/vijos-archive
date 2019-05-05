#include<stdio.h>

int m, n, happy[50][50];
long long re[50][50][50][50];

int Search(int ax, int ay, int bx, int by) {
    int a, b, c, d, e;
    if (re[ax][ay][bx][by] == 0) {
        //�� ��
        a = ax + 1;
        d = by + 1;
        if (a < n && d < m && a != bx && ay != d) {
            e = happy[a][ay] + happy[bx][d];
            e += Search(a, ay, bx, d);
            if (re[ax][ay][bx][by] < e)
                re[ax][ay][bx][by] = e;
        }
        //�� �� 
        b = ay + 1;
        c = bx + 1;
        if (b < m && c < n) {
            e = happy[ax][b] + happy[c][by];
            e += Search(ax, b, c, by);
            if (re[ax][ay][bx][by] < e)
                re[ax][ay][bx][by] = e;
        }
        //�� ��
        b = ay + 1;
        d = by + 1;
        if (b < m && d < m) {
            e = happy[ax][b] + happy[bx][d];
            e += Search(ax, b, bx, d);
            if (re[ax][ay][bx][by] < e)
                re[ax][ay][bx][by] = e;
        }
        //�� ��
        a = ax + 1;
        c = bx + 1;
        if (a < n && c < n) {
            e = happy[a][ay] + happy[c][by];
            e += Search(a, ay, c, by);
            if (re[ax][ay][bx][by] < e)
                re[ax][ay][bx][by] = e;
        }
    }
    return re[ax][ay][bx][by];
}

int main() {
    scanf("%d %d", &m, &n);
    int a, b;
    for (a = 0; a < m; a++)
        for (b = 0; b < n; b++)
            scanf("%d", &happy[b][a]);
    re[0][1][1][0] = Search(0, 1, 1, 0);
    re[0][1][1][0] += happy[0][1];
    re[0][1][1][0] += happy[1][0];
    printf("%lld\n", re[0][1][1][0]);
    return 0;
}
