#include <iostream>
#include <algorithm>
using namespace std;

int T, n;
int sticker[2][200000];
int dp[2][200000];

int main(void) {
    cin >> T;
    while(T--) {
        cin >> n;
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < n; j++)
                cin >> sticker[i][j];
        
        // 초기값
        dp[0][0] = sticker[0][0], dp[1][0] = sticker[1][0];
        dp[0][1] = sticker[1][0] + sticker[0][1];
        dp[1][1] = sticker[0][0] + sticker[1][1];

        // dp
        for(int i = 2; i < n; i++) {
            dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + sticker[0][i];
            dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + sticker[1][i];
        }
        
        cout << max({dp[0][n - 1], dp[1][n - 1]}) << endl;
    }
}