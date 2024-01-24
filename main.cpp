#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int binary_search(const int arr[], int x, int low, int high) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x) {
            return mid;
        } else if (arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    int arr[] = {3, 4, 5, 6, 7, 8, 9};
    int x = 4;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binary_search(arr, x, 0, n - 1);
    if (result == -1) {
        cout << "Element not found";
    } else {
        cout << "Element found at index " << result;
    }


    return 0;
}