#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

vector<ll> fact(MAX), inv_fact(MAX);

ll mod_pow(ll base, ll exp, ll mod = MOD) {
    ll res = 1;
    base %= mod;
    while (exp > 0) {
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();

    string s;
    cin >> s;

    int n = s.size();
    vector<int> freq(26, 0);
    for (char ch : s) freq[ch - 'a']++;

    ll res = fact[n];
    for (int f : freq) {
        if (f > 0) {
            res = res * inv_fact[f] % MOD;
        }
    }

    cout << res << "\n";
    return 0;
}
