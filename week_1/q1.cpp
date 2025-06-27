//next round
#include<iostream>
using namespace std;

int tell(int n, int k, int arr[]) {
    k = k - 1; // Convert to 0-based index

    // Move backward if value <= 0
    while (k >= 0 && arr[k] <= 0) {
        k--;
    }

    if (k < 0) return 0; // No positive value found

    // Look forward for a drop
    for (int i = k + 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            return i + 1; // Return 1-based index
        }
    }

    return n; // No drop found, return last index (1-based)
}

int main() {
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << tell(n, k, arr) << endl;
}
