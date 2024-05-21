#include <iostream>
#include <algorithm>
using namespace std;

int dp[2][302], points[302], n;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> points[i];
    dp[1][1] = points[1];
    dp[0][2] = points[2], dp[1][2] = dp[1][1] + points[2];
    for (int i = 3; i <= n; ++i) {
        dp[0][i] = max(dp[0][i - 2], dp[1][i - 2]) + points[i];
        dp[1][i] = dp[0][i - 1] + points[i];
    }
    cout << max(dp[0][n], dp[1][n]);
}