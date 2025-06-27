#include <iostream>
using namespace std;

const long long MOD = 1e9 + 7;
const long long PHI = MOD - 1;

// Function to perform modular exponentiation: (base^exp) % mod
long long mod_pow(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1)
            result = result * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        long long a, b, c;
        cin >> a >> b >> c;
        
        if (a == 0 && b == 0 && c == 0) {
            cout << "1\n"; // 0^0 is defined as 1
            continue;
        }

        long long exp = mod_pow(b, c, PHI);      // b^c mod (MOD-1)
        long long res = mod_pow(a, exp, MOD);    // a^exp mod MOD
        cout << res << '\n';
    }
    return 0;
}
