#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int MAX = 2e6 + 5;

vector<ll> fact(MAX), inv_fact(MAX);

// Modular exponentiation
ll mod_pow(ll base, ll exp, ll mod = MOD) {
    ll res = 1;
    base %= mod;
    while (exp) {
        if (exp & 1)
            res = res * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return res;
}

// Precompute factorials and inverse factorials
void precompute() {
    fact[0] = inv_fact[0] = 1;
    for (int i = 1; i < MAX; ++i)
        fact[i] = fact[i - 1] * i % MOD;
    inv_fact[MAX - 1] = mod_pow(fact[MAX - 1], MOD - 2);
    for (int i = MAX - 2; i >= 1; --i)
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
}

ll binom(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();

    int n;
    cin >> n;

    if (n % 2 != 0) {
        cout << 0 << "\n"; // odd length cannot form valid brackets
    } else {
        int k = n / 2;
        ll ans = binom(2 * k, k);
        ans = ans * mod_pow(k + 1, MOD - 2) % MOD;
        cout << ans << "\n";
    }

    return 0;
}
