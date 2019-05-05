#include<stdio.h>
#include<stdlib.h>

int main() {
    double L, V;
    scanf("%lf", &L);
    scanf("%lf", &V);
    printf("%.1lf\n", L / 1.5);
    printf("%.1lf\n", L / (1.5 * V));
    return 0;
}
