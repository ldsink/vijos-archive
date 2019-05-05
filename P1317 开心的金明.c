#include<stdio.h>

long N, M, V[25], P[25], Re[26][30001];

long Fun(long thing, long money) {
    if (thing == M)
        return 0;
    if (Re[thing][money] == 0) {
        long a, b;
        a = 0;
        if (money >= V[thing])
            a = Fun(thing + 1, money - V[thing]) + P[thing] * V[thing];
        b = Fun(thing + 1, money);
        Re[thing][money] = a > b ? a : b;
    }
    return Re[thing][money];
}

int main() {
    scanf("%ld %ld", &N, &M);
    long a, b;
    for (a = 0; a < M; a++)
        scanf("%ld %ld", &V[a], &P[a]);
    b = Fun(0, N);
    printf("%ld\n", b);
    return 0;
} 
