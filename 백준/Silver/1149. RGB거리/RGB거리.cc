#include <iostream>
#include <algorithm>
using namespace std;

int n, cost_buf;
int cost[1000][3];
int dp[1000][3];

void init() {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 3; ++j)
            dp[i][j] = 987654321;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> cost_buf;
            cost[i][j] = cost_buf;
        }
    }
    init();
    for (int i = 0; i < 3; ++i)
        dp[0][i] = cost[0][i];
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (j == 0) {
                dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
            } else if (j == 1) {
                dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
            } else if (j == 2) {
                dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
            }
        }
    }
    cout << min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
}
