#include<stdio.h>

int main() {

    int i, j, pan, money, save, budget[12];
    for (i = 0, money = 0, save = 0; i < 12; i++)
        scanf("%d", &budget[i]);
    for (i = 0, pan = 1; i < 12; i++) {
        money += 300;
        money -= budget[i];
        if (money < 0) {
            i++, pan = 0;
            break;
        } else {
            j = money / 100;
            money %= 100;
            save += j * 100;
        }
    }
    if (pan == 1)
        printf("%d", save * 6 / 5 + money);
    else
        printf("-%d", i);
    return 0;
}
