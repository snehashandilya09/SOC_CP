//equalise
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    // Try fitting by width
    if (1LL * b * c >= 1LL * a * d) {
        // Fit by width
        long long movie_area = 1LL * a * a * d;
        long long total_area = 1LL * a * b * c;
        long long empty_area = total_area - movie_area;
        long long g = gcd(empty_area, total_area);
        cout << (empty_area / g) << "/" << (total_area / g) << "\n";
    } else {
        // Fit by height
        long long movie_area = 1LL * b * b * c;
        long long total_area = 1LL * a * b * d;
        long long empty_area = total_area - movie_area;
        long long g = gcd(empty_area, total_area);
        cout << (empty_area / g) << "/" << (total_area / g) << "\n";
    }

    return 0;
}
