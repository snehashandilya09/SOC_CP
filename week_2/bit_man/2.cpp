#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        ll x, y;
        cin >> x >> y;
        if ((x & y) == 0)
            cout << 0 << '\n';
        else
            cout << -1 << '\n';
    }
    return 0;
}
