#include<stdio.h>

long N, Max, HQ[50001], HH[50001], End[50001], Times[50001];

int main() {
    scanf("%d", &N);
    long var;
    for (var = 1; var <= N; var++)
        scanf("%d %d", &HQ[var], &HH[var]);
    End[1] = 1;
    End[2] = HQ[1];
    for (var = 3; var <= N; var++)
        if (End[var - 2] == HQ[End[var - 1]])
            End[var] = HH[End[var - 1]];
        else if (End[var - 2] == HH[End[var - 1]])
            End[var] = HQ[End[var - 1]];
        else {
            printf("-1\n");
            return 0;
        }
    if (End[N] != HH[1]) {
        printf("-1\n");
        return 0;
    }
    for (var = 1; var <= N; var++)
        Times[(var + N - End[var]) % N]++;
    for (var = 0; var < N; var++)
        if (Times[var] > Max)
            Max = Times[var];
    memset(Times, 0, sizeof(Times));
    for (var = 1; var <= N; var++)
        Times[(var + End[var]) % N]++;
    for (var = 0; var < N; var++)
        if (Times[var] > Max)
            Max = Times[var];
    printf("%d\n", N - Max);
    return 0;
}
