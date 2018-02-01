#include<stdio.h>
#include<math.h>

float Cal(float x1, float y1, float x2, float y2);

float N, R, Long, Point[101][2];

int main() {
    scanf("%f %f", &N, &R);
    int temp;
    for (temp = 0; temp < N; temp++)
        scanf("%f %f", &Point[temp][0], &Point[temp][1]);
    for (temp = 0; temp < N - 1; temp++)
        Long += Cal(Point[temp][0], Point[temp][1], Point[temp + 1][0], Point[temp + 1][1]);
    Long += Cal(Point[0][0], Point[0][1], Point[temp][0], Point[temp][1]);
    Long += 2 * 3.14159 * R;
    printf("%.2f", Long);
    return 0;
}

float Cal(float x1, float y1, float x2, float y2) {
    float temp, x, y;
    x = (x1 - x2) * (x1 - x2);
    y = (y1 - y2) * (y1 - y2);
    temp = sqrt(x + y);
    return temp;
}
