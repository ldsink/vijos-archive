#include<stdio.h>

int N, M, Ans, Map[1001][1001];

int Pan1(int a, int b, int c) {
    int temp;
    for (temp = 1; b <= c; b++)
        if (Map[a][b] == 0) {
            temp = 0;
            break;
        }
    if (temp == 0)
        return 2;
    else
        return 1;
}

int Pan2(int a, int b, int c) {
    int temp;
    for (temp = 1; b <= c; b++)
        if (Map[b][a] == 0) {
            temp = 0;
            break;
        }
    if (temp == 0)
        return 2;
    else
        return 1;
}

void Search(int start, int end, int a, int b) {
    if (a < N && b < M) {
        if (Map[a + 1][b + 1] == 1 && Pan1(a + 1, end, b) == 1 && Pan2(b + 1, start, a) == 1) {
            Ans = Ans < a - start + 2 ? a - start + 2 : Ans;
            Search(start, end, a + 1, b + 1);
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);
    int a, b;
    for (a = 1; a <= N; a++)
        for (b = 1; b <= M; b++)
            scanf("%d", &Map[a][b]);
    for (a = 1; a <= N; a++)
        for (b = 1; b <= M; b++)
            if (Map[a][b] == 1)
                Search(a, b, a, b);
    if (Ans == 0)
        for (a = 1; a <= N; a++)
            for (b = 1; b <= M; b++)
                if (Map[a][b] == 1) {
                    Ans = 1;
                    goto end;
                }
    end:
    printf("%d", Ans);
    return 0;
}
