#include<stdio.h>
#include<stdlib.h>

int N, t, maxfi, fi[101], ti[101], save[101][1002];

int MaxHappy(int site, int time);

int Max(int a, int b);

int main() {
    scanf("%d", &N);
    scanf("%d", &t);
    int i;
    for (i = 0; i < N; i++)
        scanf("%d %d", &fi[i], &ti[i]);
    maxfi = MaxHappy(0, t);
    printf("%d", maxfi);
    return 0;
}

int MaxHappy(int site, int time) {
    if (save[site][time] == 0)
        if (site < N && time > 0) {
            if (time >= ti[site])
                save[site][time] = Max(MaxHappy(site + 1, time),
                                       fi[site] + MaxHappy(site + 1, time - ti[site]));
            else
                save[site][time] = MaxHappy(site + 1, time);
        }
    return save[site][time];
}

int Max(int a, int b) {
    if (a < b)
        a = b;
    return a;
}
