#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int MAX = 2e6 + 5;

vector<ll> fact(MAX), inv_fact(MAX);

ll mod_pow(ll base, ll exp, ll mod = MOD) {
    ll res = 1;
    while (exp) {
        if (exp & 1) res = res * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return res;
}

void precompute() {
    fact[0] = inv_fact[0] = 1;
    for (int i = 1; i < MAX; ++i)
        fact[i] = fact[i - 1] * i % MOD;
    inv_fact[MAX - 1] = mod_pow(fact[MAX - 1], MOD - 2);
    for (int i = MAX - 2; i >= 1; --i)
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
}

ll binom(int a, int b) {
    if (b < 0 || b > a) return 0;
    return fact[a] * inv_fact[b] % MOD * inv_fact[a - b] % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();

    int n, m;
    cin >> n >> m;

    cout << binom(n + m - 1, m) << "\n";
    return 0;
}
