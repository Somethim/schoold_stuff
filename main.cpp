#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void bubble_sort(int arr[], int size) {
    for (int step = 0; step < size; step++) {
        for (int i = 0; i < size - step; i++) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }
}


void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << "\t";
    }
    cout << "\n";
}

int main() {
    int arr[] = {5, 4, 3, 2, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sorting: \n";
    print_array(arr, size);

    bubble_sort(arr, size);

    cout << "After sorting: \n";
    print_array(arr, size);


    return 0;
}