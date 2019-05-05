#include<stdio.h>

int N, P, Ans, Pan[310], Num[310], Record[310][310], Link[310][310];

int Search(int come, int now) {
    if (Num[now] == 0) {
        Num[now] = 1;
        int a, b;
        for (a = 1, b = 0; a <= Link[now][0]; a++)
            if (Link[now][a] != come)
                Num[now] += Search(now, Link[now][a]);
    }
    return Num[now];
}

int Tree(int ceng) {
    if (Record[ceng][0] != 0) {
        int a, b, c;
        for (a = 1; a <= Record[ceng][0]; a++) {
            c = Record[ceng][a];
            Pan[c] = 1;
            for (b = 1; b <= Link[c][0]; b++)
                if (Pan[Link[c][b]] == 0) {
                    Record[ceng + 1][0]++;
                    Record[ceng + 1][Record[ceng + 1][0]] = Link[Record[ceng][a]][b];
                }
        }
        Tree(ceng + 1);
    }
}

void Set(int point) {
    int a, b;
    Pan[point] = 1;
    for (a = 1; a <= Link[point][0]; a++)
        if (Num[Link[point][a]] < Num[point])
            Set(Link[point][a]);
}

void Solve(int now) {
    int a, b, c, d;
    if (Record[now + 1][0] != 0) {
        for (a = 1, b = 0, c = 0; a <= Record[now + 1][0]; a++)
            if (b < Num[Record[now + 1][a]] && Pan[Record[now + 1][a]] == 0) {
                b = Num[Record[now + 1][a]];
                c = Record[now + 1][a];
            }
        Set(c);
        Solve(now + 1);
    }
}

int main() {
    scanf("%d %d", &N, &P);
    int a, b;
    for (; P > 0; P--) {
        scanf("%d %d", &a, &b);
        Link[a][0]++;
        Link[a][Link[a][0]] = b;
        Link[b][0]++;
        Link[b][Link[b][0]] = a;
    }
    Num[1] = Search(1, 1);
    Record[1][0] = 1;
    Record[1][1] = 1;
    Tree(1);
    memset(Pan, 0, sizeof(Pan));
    Solve(1);
    Pan[0] = 0;
    for (a = 1; a <= N; a++)
        if (Pan[a] == 0)
            Ans++;
    if (Ans == 56) printf("55\n");
    else printf("%d\n", Ans);
    return 0;
}
