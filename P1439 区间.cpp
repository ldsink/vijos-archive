#include <iostream>
#include <cmath>
#include <utility>

int array[50000][2];

void quick_sort(int left, int right) {
    if (left == right) {
        return;
    }
    int start = left;
    int end = right;

    while (start < end) {
        while (start < end) {
            if (array[start][0] > array[end][0]) {
                std::swap(array[start], array[end]);
                start++;
                break;
            } else {
                end--;
            }
        }
        while (start < end) {
            if (array[end][0] < array[start][0]) {
                std::swap(array[start], array[end]);
                end--;
                break;
            } else {
                start++;
            }
        }
    }
    if (left < start - 1) quick_sort(left, start - 1);
    if (start + 1 < right) quick_sort(start + 1, right);
}

int main() {
    int n = 0;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> array[i][0] >> array[i][1];
    }
    quick_sort(0, n - 1);

    int left = 0, right = 0;
    for (int i = 0; i < n; i++) {
        if (!left) {
            left = array[i][0];
            std::cout << left << " ";
        }
        if (!right) {
            right = array[i][1];
        }

        if (array[i][0] <= right) {
            right = std::max(array[i][1], right);
        } else {
            std::cout << right << std::endl;
            left = array[i][0];
            right = array[i][1];
            std::cout << left << " ";
        }
    }
    std::cout << right << std::endl;
    return 0;
}