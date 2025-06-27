#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;
vector<int> phi(MAX);

// Sieve to precompute Euler's Totient function
void compute_totients(int N) {
    for (int i = 1; i <= N; ++i) phi[i] = i;
    for (int i = 2; i <= N; ++i) {
        if (phi[i] == i) {
            for (int j = i; j <= N; j += i) {
                phi[j] -= phi[j] / i;
            }
        }
    }
}

// Modular exponentiation
ll mod_pow(ll base, ll exp, ll mod = MOD) {
    ll result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2) result = result * base % mod;
        base = base * base % mod;
        exp /= 2;
    }
    return result;
}

// Modular inverse
ll mod_inv(ll x) {
    return mod_pow(x, MOD - 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    compute_totients(1e6);

    int n, m;
    cin >> n >> m;

    ll total = 0;
    for (int d = 1; d * d <= n; ++d) {
        if (n % d == 0) {
            ll term1 = phi[d] * mod_pow(m, n / d) % MOD;
            total = (total + term1) % MOD;

            if (d != n / d) {
                ll term2 = phi[n / d] * mod_pow(m, d) % MOD;
                total = (total + term2) % MOD;
            }
        }
    }

    ll result = total * mod_inv(n) % MOD;
    cout << result << "\n";
    return 0;
}
