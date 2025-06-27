#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Range {
    int x, y, idx;
};

const int MAXN = 2e5 + 5;

struct BIT {
    vector<int> tree;
    int size;
    BIT(int n) : size(n), tree(n + 2) {}
    void update(int i, int v) {
        for (; i <= size; i += i & -i)
            tree[i] += v;
    }
    int query(int i) {
        int res = 0;
        for (; i > 0; i -= i & -i)
            res += tree[i];
        return res;
    }
    int query(int l, int r) {
        return query(r) - query(l - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<Range> ranges(n);
    vector<int> ys;

    for (int i = 0; i < n; ++i) {
        cin >> ranges[i].x >> ranges[i].y;
        ranges[i].idx = i;
        ys.push_back(ranges[i].y);
    }

    // Coordinate compression on y-values
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
    auto get_y = [&](int y) {
        return lower_bound(ys.begin(), ys.end(), y) - ys.begin() + 1;
    };
    int y_size = ys.size();

    // Count how many ranges each one contains
    vector<int> contains(n), contained(n);
    {
        sort(ranges.begin(), ranges.end(), [](Range &a, Range &b) {
            if (a.x != b.x) return a.x < b.x;
            return a.y > b.y;
        });
        BIT bit(y_size);
        for (int i = n - 1; i >= 0; --i) {
            int cy = get_y(ranges[i].y);
            contains[ranges[i].idx] = bit.query(cy);
            bit.update(cy, 1);
        }
    }

    // Count how many ranges contain each one
    {
        sort(ranges.begin(), ranges.end(), [](Range &a, Range &b) {
            if (a.x != b.x) return a.x < b.x;
            return a.y < b.y;
        });
        BIT bit(y_size);
        for (int i = 0; i < n; ++i) {
            int cy = get_y(ranges[i].y);
            contained[ranges[i].idx] = bit.query(y_size) - bit.query(cy - 1);
            bit.update(cy, 1);
        }
    }

    for (int c : contains) cout << c << ' ';
    cout << '\n';
    for (int c : contained) cout << c << ' ';
    cout << '\n';

    return 0;
}
