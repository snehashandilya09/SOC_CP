//numbers
#include <iostream>
#include <vector>
using namespace std;

int min_seconds_to_sort(vector<int>& a) {
    int max_so_far = a[0];
    int max_diff = 0;

    for (int i = 1; i < a.size(); i++) {
        if (a[i] < max_so_far) {
            max_diff = max(max_diff, max_so_far - a[i]);
        } else {
            max_so_far = a[i];
        }
    }

    int T = 0;
    while ((1LL << T) <= max_diff) {
        T++;
    }
    return T;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& x : a) cin >> x;
        cout << min_seconds_to_sort(a) << endl;
    }
}
