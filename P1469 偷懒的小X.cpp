#include <iostream>
#include <algorithm>

int array[65536];
int result[65536];

void arrangement(int sorted_offset, int tree_offset, int num) {
    result[tree_offset] = array[sorted_offset];
    if (num == 1) {
        return;
    }
    arrangement(sorted_offset + num, tree_offset * 2, num >> 1);
    arrangement(sorted_offset + 1, tree_offset * 2 + 1, num >> 1);
}

int main() {
    int n = 0;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> array[i];
    }
    std::sort(array + 1, array + n + 1);
    arrangement(1, 1, (n + 1) >> 1);

    for (int i = 1; i < n; i++)
        std::cout << result[i] << " ";
    std::cout << result[n] << std::endl;
    return 0;
}