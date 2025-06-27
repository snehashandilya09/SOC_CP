#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

ll mod_pow(ll base, ll exp, ll mod = MOD) {
    ll res = 1;
    base %= mod;
    while (exp) {
        if (exp & 1) res = res * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return res;
}

ll mod_inv(ll a) {
    return mod_pow(a, MOD - 2);
}

int main() {
    int n;
    cin >> n;

    vector<pair<ll, ll>> primes(n);
    for (int i = 0; i < n; ++i) {
        cin >> primes[i].first >> primes[i].second;
    }

    ll num_divisors = 1;
    ll sum_divisors = 1;
    ll prod_divisors = 1;
    ll d = 1;

    for (auto [p, k] : primes) {
        num_divisors = num_divisors * (k + 1) % MOD;

        ll num = (mod_pow(p, k + 1) - 1 + MOD) % MOD;
        ll den = mod_inv(p - 1);
        sum_divisors = sum_divisors * num % MOD * den % MOD;
    }

    for (auto [p, k] : primes) {
        ll new_d = d * (k + 1) % (MOD - 1);
        ll exp_total = k % (MOD - 1) * (d % (MOD - 1)) % (MOD - 1);
        exp_total = exp_total * mod_inv(2) % (MOD - 1);
        prod_divisors = prod_divisors * mod_pow(p, exp_total) % MOD;
        d = new_d;
    }

    cout << num_divisors << " " << sum_divisors << " " << prod_divisors << "\n";
    return 0;
}
