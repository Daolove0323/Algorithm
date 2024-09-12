#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int> > land)
{
    vector<vector<int>> dp(land.size(), vector<int>(4, 0));
    for (int i = 0; i < 4; ++i) dp[0][i] = land[0][i];
    for (int i = 1; i < dp.size(); ++i) {
        for (int j = 0; j < 4; ++j) {
            int biggestLast = 0;
            for (int k = 0; k < 4; ++k) {
                if (j == k) continue;
                biggestLast = max(biggestLast, dp[i - 1][k]);
            }
            dp[i][j] = biggestLast + land[i][j];
        }
    }
    return max({dp[land.size() - 1][0], dp[land.size() - 1][1], dp[land.size() - 1][2], dp[land.size() - 1][3]});
}