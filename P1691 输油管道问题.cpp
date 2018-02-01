#include <iostream>
#include <cmath>

int array[10000];

void quick_sort(int left, int right) {
    if (left == right) {
        return;
    }
    int start = left;
    int end = right;
    int value = array[start];

    while (start < end) {
        while (start < end) {
            if (value > array[end]) {
                array[start] = array[end];
                start++;
                break;
            } else {
                end--;
            }
        }
        while (start < end) {
            if (value < array[start]) {
                array[end] = array[start];
                end--;
                break;
            } else {
                start++;
            }
        }
    }
    array[start] = value;
    if (left < start - 1) quick_sort(left, start - 1);
    if (start + 1 < right) quick_sort(start + 1, right);
}

int main() {
    int n = 0;
    std::cin >> n;
    for (int i = 0, j; i < n; i++) {
        std::cin >> j >> array[i];
    }
    quick_sort(0, n - 1);
    int middle = (0 + n - 1) >> 1;
    int result = 0;
    for (int i = 0; i < n; i++) {
        result += abs(array[i] - array[middle]);
    }

    std::cout << result << std::endl;
    return 0;
}