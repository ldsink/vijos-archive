#include <iostream>
#include <algorithm>

int vertical[10000];
int horizon[10000];

int main() {
    int n = 0;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> horizon[i] >> vertical[i];
    }
    int result = 0;
    int middle = n >> 1;

    std::sort(vertical, vertical + n);
    for (int i = 0; i < n; i++) {
        result += abs(vertical[i] - vertical[middle]);
    }

    std::sort(horizon, horizon + n);
    for (int i = 0; i < n; i++) {
        horizon[i] -= i;
    }
    std::sort(horizon, horizon + n);
    for (int i = 0; i < n; i++) {
        result += abs(horizon[i] - horizon[middle]);
    }
    std::cout << result << std::endl;
    return 0;
}
