#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;

    if (n == 0) {
        cout << 1 << endl;
    } else {
        int pattern[] = {6, 8, 4, 2};
        cout << pattern[n % 4] << endl;
    }

    return 0;
}
