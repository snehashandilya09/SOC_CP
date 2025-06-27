#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int tell(int m, int n, vector<vector<int>> &arr) {
    int sum = 0;
    for (int i = 0; i < m / 2; i++) {
        for (int j = 0; j < n / 2; j++) {
            vector<int> vals;
            vals.push_back(arr[i][j]);
            vals.push_back(arr[i][n - 1 - j]);
            vals.push_back(arr[m - 1 - i][j]);
            vals.push_back(arr[m - 1 - i][n - 1 - j]);
            sort(vals.begin(), vals.end());
            int median = (vals[1] + vals[2]) / 2;
            for (int x : vals)
                sum += abs(x - median);
        }
    }

    // If m is odd, process the middle row
    if (m % 2 == 1) {
        int row = m / 2;
        for (int j = 0; j < n / 2; j++) {
            int a = arr[row][j];
            int b = arr[row][n - 1 - j];
            int median = (a + b) / 2;
            sum += abs(a - median) + abs(b - median);
        }
    }

    // If n is odd, process the middle column
    if (n % 2 == 1) {
        int col = n / 2;
        for (int i = 0; i < m / 2; i++) {
            int a = arr[i][col];
            int b = arr[m - 1 - i][col];
            int median = (a + b) / 2;
            sum += abs(a - median) + abs(b - median);
        }
    }

    return sum;
}

int main() {
    int t;
    cin >> t;
    vector<int> results;
    while (t--) {
        int m, n;
        cin >> m >> n;
        vector<vector<int>> arr(m, vector<int>(n));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];
        results.push_back(tell(m, n, arr));
    }

    for (int res : results) {
        cout << res << endl;
    }
}
