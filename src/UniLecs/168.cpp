#include <iostream>
#include <vector>
using namespace std;


int getMissedItem(int* arr, int size) {
    int mn = 1001, mx = -1, s = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] < mn) mn = arr[i];
        if (arr[i] > mx) mx = arr[i];
        s += arr[i];
    }
    return ((mn + mx) * (size + 1) / 2) - s;
}


int main() {
    int len;
    cout << "Array length: "; cin >> len;
    int arr[len];
    for (int i = 0; i < len; i++) cin >> arr[i];
    cout << getMissedItem(arr, len) << endl;
}
