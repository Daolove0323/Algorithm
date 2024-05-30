#include <iostream>
using namespace std;

int t, m, n, x, y;

int gcd(int a, int b) {
    if (a < b) { int tmp = a; a = b; b = tmp; }
    if (a % b == 0) return b;
    return gcd(b, a % b);
}
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    cin >> t;
    while(t--) {
        cin >> m >> n >> x >> y;
        int final_date = lcm(m, n);
        int _m = 0, _n = 0;
        while (true) {
            int M = m * _m + x;
            int N = n * _n + y;
            if (M > final_date || N > final_date) { cout << -1 << '\n'; break; }
            if (M == N) { cout << M << '\n'; break; }
            else if (M > N) ++_n;
            else ++_m;
        }
    }
}