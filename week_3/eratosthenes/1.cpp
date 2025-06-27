#include <iostream>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, n;
    cin >> x >> n;

    set<int> lights;
    multiset<int> lengths;

    lights.insert(0);
    lights.insert(x);
    lengths.insert(x); // initial full segment

    for (int i = 0; i < n; ++i) {
        int p;
        cin >> p;

        auto upper = lights.upper_bound(p);
        auto lower = prev(upper);

        int l = *lower;
        int r = *upper;

        // Remove old segment
        lengths.erase(lengths.find(r - l));

        // Add new segments
        lengths.insert(p - l);
        lengths.insert(r - p);

        lights.insert(p);

        // Get max length
        cout << *lengths.rbegin() << " ";
    }

    cout << "\n";
    return 0;
}
