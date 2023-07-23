
#include <iostream>
#include <algorithm>

bool descendingComparator(int a, int b) {
    return a > b;
}

int main() {
    int arr[] = {5, 2, 8, 1, 9, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    std::sort(arr, arr + size, descendingComparator);

    std::cout << "Sorted array in descending order: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}