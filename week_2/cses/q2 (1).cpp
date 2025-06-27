#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<tuple<int, int, int>> ranges(n); // (x, y, idx)
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        ranges[i] = {x, y, i};
    }

    // Sort by x increasing, y decreasing
    sort(ranges.begin(), ranges.end(), [](auto &a, auto &b) {
        auto [x1, y1, i1] = a;
        auto [x2, y2, i2] = b;
        if (x1 != x2) return x1 < x2;
        return y1 > y2;
    });

    vector<int> contains(n), contained(n);
    int max_y = 0;

    // Find "is contained"
    for (auto &[x, y, idx] : ranges) {
        if (y <= max_y)
            contained[idx] = 1;
        max_y = max(max_y, y);
    }

    // Find "contains"
    int min_y = 1e9 + 1;
    for (int i = n - 1; i >= 0; --i) {
        auto &[x, y, idx] = ranges[i];
        if (y >= min_y)
            contains[idx] = 1;
        min_y = min(min_y, y);
    }

    for (int v : contains) cout << v << ' ';
    cout << '\n';
    for (int v : contained) cout << v << ' ';
    cout << '\n';

    return 0;
}
