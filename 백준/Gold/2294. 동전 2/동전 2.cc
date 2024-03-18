#include <iostream>
#include <cstring>
using namespace std;

int n, k;
int coin[101];
int dp[10001];

int main(void) {
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> coin[i];
    for(int i = 0; i <= k; i++) dp[i] = 10001;

    // dp
    dp[0] = 0;
    for(int i = 0; i <= k; i++)
        for(int j = 0; j < n; j++)
            if(i - coin[j] < 0) continue;
            else dp[i] = min(dp[i], dp[i - coin[j]] + 1);

    if(dp[k] == 10001) cout << -1;
    else cout << dp[k];
}