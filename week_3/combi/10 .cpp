#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

// Modular exponentiation
ll mod_pow(ll base, ll exp, ll mod = MOD) {
    ll res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2) res = res * base % mod;
        base = base * base % mod;
        exp /= 2;
    }
    return res;
}

// Modular inverse of 4
const ll INV_4 = mod_pow(4, MOD - 2);

int main() {
    ll n;
    cin >> n;

    ll total = 0;

    // 0° rotation: all cells free
    ll fix_0 = mod_pow(2, n * n);
    total = (total + fix_0) % MOD;

    // 180° rotation: each cell pairs with its opposite
    ll half = (n * n) / 2;
    ll fix_180 = mod_pow(2, half);
    total = (total + fix_180) % MOD;

    // 90° and 270° rotation: each orbit of 4 must be same
    ll num_orbits = (n * n) / 4;
    ll fix_90 = mod_pow(2, num_orbits);
    total = (total + fix_90 + fix_90) % MOD;

    // Final answer: divide by 4
    ll result = total * INV_4 % MOD;

    cout << result << "\n";
    return 0;
}
    