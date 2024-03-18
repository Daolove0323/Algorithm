#include <iostream>
using namespace std;

int n, k;
int coin[100];
int dp[10001];

int main(void) {
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> coin[i];

    dp[0] = 1;
    for(int c = 0; c < n; c++)
        for(int v = coin[c]; v <= k; v++)
            dp[v] = dp[v] + dp[v - coin[c]];
    
    cout << dp[k];
}
