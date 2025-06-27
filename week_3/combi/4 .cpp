#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

ll derangement[MAX];

void precompute() {
    derangement[0] = 1;
    derangement[1] = 0;
    for (int i = 2; i < MAX; ++i) {
        derangement[i] = (i - 1) * (derangement[i - 1] + derangement[i - 2]) % MOD;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    precompute();

    cout << derangement[n] << "\n";
    return 0;
}
