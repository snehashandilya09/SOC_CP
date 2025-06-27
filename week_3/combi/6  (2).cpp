#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;

// Function to compute LCM of two numbers
ll lcm(ll a, ll b) {
    return a / __gcd(a, b) * b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        --p[i]; // Convert to 0-based indexing
    }

    vector<bool> visited(n, false);
    ll result = 1;

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            int cur = i;
            int len = 0;
            while (!visited[cur]) {
                visited[cur] = true;
                cur = p[cur];
                ++len;
            }
            result = lcm(result, len);
            result %= MOD;
        }
    }

    cout << result << "\n";
    return 0;
}
