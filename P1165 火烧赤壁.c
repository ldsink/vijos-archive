#include<stdio.h>

#define maxn 50000

long long n, start[maxn + 10], end[maxn + 10], ans, stack[maxn + 10], top, INF;

void quicksort(long long *a, long long low, long long high) {
    long long l = low, r = high, x = a[low];
    while (l < r) {
        while (l < r && a[r] >= x) --r;
        a[l] = a[r];
        while (l < r && a[l] <= x) ++l;
        a[r] = a[l];
    }
    a[l] = x;
    if (low < l - 1)
        quicksort(a, low, l - 1);
    if (l + 1 < high)
        quicksort(a, l + 1, high);
}

int main() {
    long long i, j, up, t, o;
    scanf("%lld", &n);
    for (i = 1; i <= n; ++i)
        scanf("%lld %lld", &start[i], &end[i]);
    quicksort(start, 1, n);
    quicksort(end, 1, n);
    for (INF = 1, i = 1; i <= 11; ++i)
        INF *= 10;
    start[n + 1] = end[n + 1] = INF;
    i = j = 1;
    up = n * 2;
    ans = 0;
    top = 0;
    for (o = 1; o <= up; ++o)
        if (start[i] <= end[j]) {
            stack[++top] = start[i];
            i++;
        } else {
            t = stack[top--];
            if (0 == top)
                ans += end[j] - t;
            j++;
        }
    printf("%lld\n", ans);
    return 0;
}
