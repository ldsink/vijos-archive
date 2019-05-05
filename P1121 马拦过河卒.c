#include<stdio.h>
#include<stdlib.h>

int Bx, By, Mx, My, map[16][16], way[16][16];

int Pan(int a, int b);

int Find(int a, int b);

void Zudang();

int main() {
    int Way;
    scanf("%d %d %d %d", &Bx, &By, &Mx, &My);
    Zudang();
    Way = Find(Bx, By);
    printf("%d", Way);
    return 0;
}

void Zudang() {
    map[Mx][My] = 1;
    if (Pan(Mx - 1, My + 2) == 1)
        map[Mx - 1][My + 2] = 1;
    if (Pan(Mx - 1, My - 2) == 1)
        map[Mx - 1][My - 2] = 1;
    if (Pan(Mx + 1, My + 2) == 1)
        map[Mx + 1][My + 2] = 1;
    if (Pan(Mx + 1, My - 2) == 1)
        map[Mx + 1][My - 2] = 1;
    if (Pan(Mx + 2, My - 1) == 1)
        map[Mx + 2][My - 1] = 1;
    if (Pan(Mx - 2, My - 1) == 1)
        map[Mx - 2][My - 1] = 1;
    if (Pan(Mx + 2, My + 1) == 1)
        map[Mx + 2][My + 1] = 1;
    if (Pan(Mx - 2, My + 1) == 1)
        map[Mx - 2][My + 1] = 1;
}

int Pan(int a, int b) {
    if (0 <= a && a < 16 && 0 <= b && b < 16)
        return 1;
    else
        return 0;
}

int Find(int a, int b) {
    if (a >= 0 && b >= 0) {
        if (map[a][b] == 1)
            way[a][b] = 0;
        else if (a == 0 && b == 0)
            way[a][b] = 1;
        else if (way[a][b] == 0)
            way[a][b] = Find(a - 1, b) + Find(a, b - 1);
        return way[a][b];
    } else
        return 0;
}
