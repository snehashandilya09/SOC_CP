#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

// Fast exponentiation (base^exp % mod)
ll mod_pow(ll base, ll exp, ll mod) {
    ll result = 1;
    base %= mod;
    while (exp) {
        if (exp & 1) result = result * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return result;
}

// Modular inverse (Fermat's little theorem)
ll mod_inv(ll a, ll mod) {
    return mod_pow(a, mod - 2, mod);
}

// Factorization using trial division
map<ll, ll> factorize(ll a) {
    map<ll, ll> factors;
    for (ll i = 2; i * i <= a; ++i) {
        while (a % i == 0) {
            factors[i]++;
            a /= i;
        }
    }
    if (a > 1) factors[a]++;
    return factors;
}

int main() {
    freopen("sumdiv.in", "r", stdin);
    freopen("sumdiv.out", "w", stdout);

    ll A, B;
    cin >> A >> B;

    if (B == 0) {
        cout << 1 << endl; // A^0 = 1 → sum of divisors = 1
        return 0;
    }

    map<ll, ll> factors = factorize(A);

    ll result = 1;
    for (auto [p, e] : factors) {
        ll exp = e * B;
        ll num = (mod_pow(p, exp + 1, MOD) - 1 + MOD) % MOD;
        ll denom = mod_inv(p - 1, MOD);
        result = result * (num * denom % MOD) % MOD;
    }

    cout << result << endl;
    return 0;
}
