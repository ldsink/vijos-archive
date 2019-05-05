#include<stdio.h>

int Ctime, Mtime, Day;

int main() {
    for (Day = 7; Day > 0; Day--) {
        scanf("%d %d", &Ctime, &Mtime);
        if (Ctime + Mtime > 8) {
            Day = (8 - Day);
            break;
        }
    }
    printf("%d", Day);
    return 0;
}
