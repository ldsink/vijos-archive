#include<stdio.h>

int N, M, Num[81][81], Re[81][81][50], Two[81][50], Ans[50];

void Search(int q, int h, int floor, int times) {
    if (q <= h && Re[q][h][49] == 0) {
        int a, b;
        int A[50] = {0}, B[50] = {0};
        //ȡǰһ������ֵ���� A��
        Search(q + 1, h, floor, times + 1);
        A[49] = Two[times][0] - 1;
        a = 0;
        b = 0;
        while (a <= A[49]) {
            A[a] = Num[floor][q] * Two[times][a + 1];
            A[a] += b;
            b = A[a] / 10000;
            A[a] %= 10000;
            while (a == A[49] && b != 0)
                A[49]++;
            a++;
        }
        if (A[49] < Re[q + 1][h][49])
            A[49] = Re[q + 1][h][49];
        a = 0;
        b = 0;
        while (a <= A[49]) {
            A[a] += Re[q + 1][h][a];
            A[a] += b;
            b = A[a] / 10000;
            A[a] %= 10000;
            while (a == A[49] && b != 0)
                A[49]++;
            a++;
        }
        //ȡǰһ������ֵ���� B��
        Search(q, h - 1, floor, times + 1);
        B[49] = Two[times][0] - 1;
        a = 0;
        b = 0;
        while (a <= B[49]) {
            B[a] = Num[floor][h] * Two[times][a + 1];
            B[a] += b;
            b = B[a] / 10000;
            B[a] %= 10000;
            while (a == B[49] && b != 0)
                B[49]++;
            a++;
        }
        if (B[49] < Re[q][h - 1][49])
            B[49] = Re[q][h - 1][49];
        a = 0;
        b = 0;
        while (a <= B[49]) {
            B[a] += Re[q][h - 1][a];
            B[a] += b;
            b = B[a] / 10000;
            B[a] %= 10000;
            while (a == B[49] && b != 0)
                B[49]++;
            a++;
        }
        //ȡ A B ������ֵ��  Re[q][h];
        a = 0;
        if (A[49] > B[49])
            a = 1;
        else if (A[49] == B[49])
            for (b = A[49]; b >= 0; b--) {
                if (A[b] > B[b])
                    a = 1;
                else if (A[b] < B[b])
                    break;
            }
        if (a == 1) {
            Re[q][h][49] = A[49];
            for (b = 0; b <= A[49]; b++)
                Re[q][h][b] = A[b];
        } else {
            Re[q][h][49] = B[49];
            for (b = 0; b <= B[49]; b++)
                Re[q][h][b] = B[b];
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);
    int a, b, c;
    for (a = 0; a < N; a++)
        for (b = 0; b < M; b++)
            scanf("%d", &Num[a][b]);
    //���� 2 �� M �η��� 
    Two[0][0] = 1;
    Two[0][1] = 1;
    for (a = 0; a < M; a++) {
        b = 1;
        c = 0;
        Two[a + 1][0] = Two[a][0];
        while (b <= Two[a + 1][0]) {
            Two[a + 1][b] = 2 * Two[a][b];
            Two[a + 1][b] += c;
            c = Two[a + 1][b] / 10000;
            Two[a + 1][b] %= 10000;
            if (c != 0 && b == Two[a + 1][0])
                Two[a + 1][0]++;
            b++;
        }
    }
    //�߾��ȶ�̬�滮��
    for (a = 0; a < N; a++) {
        Search(0, M - 1, a, 1);
        Ans[49] = Ans[49] > Re[0][M - 1][49] ? Ans[49] : Re[0][M - 1][49];
        b = 0;
        c = 0;
        while (c <= Ans[49]) {
            Ans[c] += Re[0][M - 1][c];
            Ans[c] += b;
            b = Ans[c] / 10000;
            Ans[c] %= 10000;
            if (b != 0 && c == Ans[49])
                Ans[49]++;
            c++;
        }
        memset(Re, 0, sizeof(Re));
    }
    //�߾��ȴ������ 
    printf("%d", Ans[Ans[49]]);
    for (a = Ans[49] - 1; a >= 0; a--) {
        if (Ans[a] > 999)
            printf("%d", Ans[a]);
        else if (Ans[a] > 99)
            printf("0%d", Ans[a]);
        else if (Ans[a] > 9)
            printf("00%d", Ans[a]);
        else
            printf("000%d", Ans[a]);
    }
    return 0;
}
