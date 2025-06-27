#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> fact(21);

void precompute_factorials() {
    fact[0] = 1;
    for (int i = 1; i <= 20; ++i) {
        fact[i] = fact[i - 1] * i;
    }
}

// Return the k-th permutation (1-based index)
vector<int> get_kth_permutation(int n, ll k) {
    vector<int> nums;
    for (int i = 1; i <= n; ++i) nums.push_back(i);

    vector<int> result;
    --k; // Convert to 0-based index

    for (int i = n; i >= 1; --i) {
        ll idx = k / fact[i - 1];
        result.push_back(nums[idx]);
        nums.erase(nums.begin() + idx);
        k %= fact[i - 1];
    }
    return result;
}

// Return the rank of the given permutation (1-based index)
ll get_permutation_index(int n, const vector<int>& perm) {
    ll k = 1;
    vector<int> nums;
    for (int i = 1; i <= n; ++i) nums.push_back(i);

    for (int i = 0; i < n; ++i) {
        int pos = find(nums.begin(), nums.end(), perm[i]) - nums.begin();
        k += pos * fact[n - 1 - i];
        nums.erase(nums.begin() + pos);
    }

    return k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute_factorials();

    int t;
    cin >> t;
    while (t--) {
        int type;
        cin >> type;
        if (type == 1) {
            int n;
            ll k;
            cin >> n >> k;
            vector<int> perm = get_kth_permutation(n, k);
            for (int x : perm)
                cout << x << " ";
            cout << "\n";
        } else {
            int n;
            cin >> n;
            vector<int> perm(n);
            for (int i = 0; i < n; ++i)
                cin >> perm[i];
            cout << get_permutation_index(n, perm) << "\n";
        }
    }

    return 0;
}
