#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int MAX = 2e6 + 5;

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

ll binom(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();

    int n;
    string prefix;
    cin >> n >> prefix;

    int k = prefix.size();
    int open_used = 0, close_used = 0;

    for (char c : prefix) {
        if (c == '(') open_used++;
        else close_used++;
        if (close_used > open_used) {
            cout << 0 << "\n"; // invalid prefix
            return 0;
        }
    }

    int total_remaining = n - k;
    if ((n % 2 != 0) || total_remaining < 0) {
        cout << 0 << "\n"; // odd length or overused
        return 0;
    }

    int balance = open_used - close_used;
    int needed_open = (total_remaining + balance) / 2;
    int needed_close = total_remaining - needed_open;

    if ((total_remaining + balance) % 2 != 0 || needed_open < 0 || needed_close < 0) {
        cout << 0 << "\n"; // invalid split
        return 0;
    }

    // Use Ballot number: C(a + b, a) - C(a + b, a + 1)
    ll res = (binom(total_remaining, needed_open) - binom(total_remaining, needed_open + 1) + MOD) % MOD;
    cout << res << "\n";

    return 0;
}
