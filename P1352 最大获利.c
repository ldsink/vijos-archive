/*
Author: ZHOU Cheng
Date: 2010-7-13
Dinic Algorithm
*/

// NOI 2006 第二试 最大获利

#include <stdio.h>

#define oo 100000000
#define Min(a, b) ((a)>(b)?(b):(a))

int N, M, P[5001], A[50001], B[50001], C[50001];
int S, T, Count;
struct Edge {
    int st, en, flow, next, opp;
} NEdge[2000000];
int Level[60000], Point[60000], Line[60000];

void Set_edge(int st, int en, int flow) {
    NEdge[Count].st = st;
    NEdge[Count].en = en;
    NEdge[Count].flow = flow;
    NEdge[Count].next = Point[st];
    Point[st] = Count;
    NEdge[Count].opp = Count + 1;
    ++Count;
    NEdge[Count].st = en;
    NEdge[Count].en = st;
    NEdge[Count].flow = 0;
    NEdge[Count].next = Point[en];
    Point[en] = Count;
    NEdge[Count].opp = Count - 1;
    ++Count;
}

int Make_level() {
    int a, b, c;
    memset(Level, 0, sizeof(Level));
    c = 0;
    Line[c] = S;
    c++;
    Level[S] = 1;
    for (a = 0; a < c; a++)
        for (b = Point[Line[a]]; b != -1; b = NEdge[b].next)
            if (NEdge[b].flow > 0 && Level[NEdge[b].en] == 0) {
                Level[NEdge[b].en] = Level[NEdge[b].st] + 1;
                Line[c++] = NEdge[b].en;
            }
    return (Level[T] > 0);
}

int Fun(int point, int alpha) {
    if (point == T) return alpha;
    int p, pp, temp, flow = 0;
    for (p = Point[point]; p != -1; p = NEdge[p].next) {
        pp = NEdge[p].en;
        if (NEdge[p].flow > 0 && Level[point] + 1 == Level[pp]) {
            temp = Fun(pp, Min(alpha - flow, NEdge[p].flow));
            NEdge[p].flow -= temp;
            pp = NEdge[p].opp;
            NEdge[pp].flow += temp;
            flow += temp;
        }
    }
    return flow;
}

int main() {
    scanf("%d %d", &N, &M);
    int a, b;
    for (a = 1; a <= N; a++)
        scanf("%d", &P[a]);
    for (a = 1; a <= M; a++)
        scanf("%d %d %d", &A[a], &B[a], &C[a]);

    //Build
    S = 0;
    T = N + M + 1;;
    for (a = S; a <= T; a++) Point[a] = -1;
    for (a = 1; a <= N; a++) Set_edge(S, a, P[a]);
    for (a = 1; a <= M; a++) {
        Set_edge(A[a], N + a, oo);
        Set_edge(B[a], N + a, oo);
    }
    for (a = 1; a <= M; a++) Set_edge(N + a, T, C[a]);

    //Dinic
    a = b = 0;
    while (Make_level())
        while (b = Fun(S, oo))
            a += b;

    for (b = 1, a = -a; b <= M; b++) a += C[b];
    printf("%d\n", a);

    return 0;
}