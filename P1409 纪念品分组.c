#include<stdio.h>

int W, G, N, Price[30000];

void KP(int st, int en) {
    int a, b, c;
    a = st;
    b = en;
    c = Price[a];
    while (a < b) {
        while (a < b) {
            if (Price[b] < c) {
                Price[a] = Price[b];
                break;
            }
            b--;
        }
        while (a < b) {
            if (Price[a] > c) {
                Price[b] = Price[a];
                break;
            }
            a++;
        }
    }
    Price[a] = c;
    if (st < a - 1)
        KP(st, a - 1);
    if (a + 1 < en)
        KP(a + 1, en);
}

void Find(int st, int en) {
    if (st <= en) {
        if (Price[st] + Price[en] <= W) {
            N++;
            Find(st + 1, en - 1);
        } else {
            N++;
            Find(st, en - 1);
        }
    }
}

int main() {
    scanf("%d %d", &W, &G);
    int a;
    for (a = 0; a < G; a++)
        scanf("%d", &Price[a]);
    KP(0, G - 1);
    Find(0, G - 1);
    printf("%d\n", N);
    return 0;
}
