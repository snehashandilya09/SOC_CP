#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 998244353;

struct Linear {
    ll a, b; // f(x) = ax + b

    Linear(ll a = 1, ll b = 0) : a(a), b(b) {}

    // Compose this with other: f(g(x)) = a1 * a2 x + a1 * b2 + b1
    Linear operator*(const Linear& other) const {
        return Linear((a * other.a) % MOD, (a * other.b + b) % MOD);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    deque<Linear> funcs;
    deque<Linear> prefix; // prefix[i] is composition of f[0]*...*f[i]

    while (Q--) {
        int type;
        cin >> type;

        if (type == 0) {
            ll a, b;
            cin >> a >> b;
            funcs.emplace_back(a, b);
            if (prefix.empty()) {
                prefix.emplace_back(a, b);
            } else {
                prefix.emplace_back(prefix.back() * Linear(a, b));
            }
        } else if (type == 1) {
            funcs.pop_front();
            prefix.clear();
            Linear curr(1, 0);
            for (auto& f : funcs) {
                curr = curr * f;
                prefix.push_back(curr);
            }
        } else if (type == 2) {
            ll x;
            cin >> x;
            if (prefix.empty()) {
                cout << x << '\n';
            } else {
                Linear composed = prefix.back();
                ll result = (composed.a * x + composed.b) % MOD;
                cout << result << '\n';
            }
        }
    }

    return 0;
}
