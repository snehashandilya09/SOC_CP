#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool is_triangle(ll a, ll b, ll c) {
    return a + b > c && a + c > b && b + c > a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while (t--) {
        ll x;
        cin >> x;

        bool found = false;
        for (int i = 1; i <= 30; ++i) {
            ll y = (1LL << i);
            if (y >= x) break;
            ll z = x ^ y;
            if (z == 0 || z >= x + y) continue;
            if (is_triangle(x, y, z)) {
                cout << y << '\n';
                found = true;
                break;
            }
        }
        if (!found) cout << -1 << '\n';
    }
    return 0;
}
