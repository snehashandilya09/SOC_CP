#include<iostream>
#include<vector>
#include<unordered_map>
#include<cmath>
using namespace std;

int main() {
    long int n;
    cin >> n;
    vector<long int> arr(2 * n);
    unordered_map<long int, vector<long int>> mpp;

    for (long int i = 0; i < 2 * n; i++) {
        cin >> arr[i];
        mpp[arr[i]].push_back(i + 1);  // 1-based indexing
    }

    long int posA = 1, posB = 1; // starting at house 1
    long long total = 0;

    for (long int i = 1; i <= n; i++) {
        auto &v = mpp[i];
        long int x = v[0], y = v[1];

        // Try both assignments and choose the one with smaller total cost
        long long option1 = abs(posA - x) + abs(posB - y);
        long long option2 = abs(posA - y) + abs(posB - x);

        if (option1 <= option2) {
            total += option1;
            posA = x;
            posB = y;
        } else {
            total += option2;
            posA = y;
            posB = x;
        }
    }

    cout << total << endl;
    return 0;
}
