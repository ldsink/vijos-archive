#include<stdio.h>
#include<math.h>

int main() {
    double m, n, r, min;
    scanf("%lf %lf %lf", &m, &n, &r);
    if (n >= m)
        printf("%.3lf", r);
    else {
        n -= m;
        min = sqrt(n * n + r * r);
        printf("%.3lf", min);
    }
    return 0;
}
