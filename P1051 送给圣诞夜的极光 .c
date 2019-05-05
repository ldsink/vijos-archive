#include<stdio.h>

int n, m, count;
char map[100][100];

void Find(int a, int b) {
    map[a][b] = '-';
    if (a - 2 >= 0 && map[a - 2][b] == '#')
        Find(a - 2, b);
    if (a - 1 >= 0 && map[a - 1][b] == '#')
        Find(a - 1, b);
    if (a - 1 >= 0 && b + 1 < m && map[a - 1][b + 1] == '#')
        Find(a - 1, b + 1);
    if (a - 1 >= 0 && b - 1 >= 0 && map[a - 1][b - 1] == '#')
        Find(a - 1, b - 1);
    if (b + 2 < m && map[a][b + 2] == '#')
        Find(a, b + 2);
    if (b + 1 < m && map[a][b + 1] == '#')
        Find(a, b + 1);
    if (b - 1 >= 0 && map[a][b - 1] == '#')
        Find(a, b - 1);
    if (b - 2 >= 0 && map[a][b - 2] == '#')
        Find(a, b - 2);
    if (a + 1 < n && b + 1 < m && map[a + 1][b + 1] == '#')
        Find(a + 1, b + 1);
    if (a + 1 < n && b - 1 >= 0 && map[a + 1][b - 1] == '#')
        Find(a + 1, b - 1);
    if (a + 1 < n && map[a + 1][b] == '#')
        Find(a + 1, b);
    if (a + 2 < n && map[a + 2][b] == '#')
        Find(a + 2, b);
}

int main() {
    scanf("%d %d", &n, &m);
    int i, j;
    char temp;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            while (1) {
                scanf("%c", &temp);
                if (temp == '#' || temp == '-') {
                    map[i][j] = temp;
                    break;
                }
            }
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            if (map[i][j] == '#') {
                Find(i, j);
                count++;
            }
    printf("%d", count);
    return 0;
}
