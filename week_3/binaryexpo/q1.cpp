#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
const ll PHI = MOD - 1; // For Fermat's reduction

ll mod_pow(ll base, ll exp, ll mod) {
    ll res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) res = res * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--) {
        ll a, b, c;
        cin >> a >> b >> c;

        if (a == 0 && b == 0 && c == 0) {
            cout << "1\n"; // 0^0 = 1
            continue;
        }

        if (a == 0) {
            cout << "0\n"; // 0^x = 0 for x > 0
            continue;
        }

        ll exponent = mod_pow(b, c, PHI); // Reduce using Fermat
        ll result = mod_pow(a, exponent, MOD);
        cout << result << '\n';
    }

    return 0;
}
