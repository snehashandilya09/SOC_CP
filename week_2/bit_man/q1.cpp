#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        ll n, x;
        cin >> n >> x;

        if (n == 1) {
            if (x == 0) cout << -1 << '\n';
            else cout << x << '\n';
        }
        else if (n == 2) {
            if (x == 0) cout << 2 << '\n';
            else if (x == 1) cout << 5 << '\n';
            else cout << (x + 2) << '\n';
        }
        else {
            cout << (n + x) << '\n';
        }
    }

    return 0;
}
