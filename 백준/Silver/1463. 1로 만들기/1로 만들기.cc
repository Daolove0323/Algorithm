#include <iostream>
using namespace std;

int N;
int dp[1000001];

int main() {
    cin >> N;
    for(int i = 0; i <= 1000000; ++i) dp[i] = 987654321;
    dp[1] = 0;
    for (int i = 1; i <= N; ++i) {
        if(i + 1 <= N) dp[i + 1] = min(dp[i + 1], dp[i] + 1);
        if(i * 2 <= N)  dp[i * 2] = min(dp[i * 2], dp[i] + 1);
        if(i * 3 <= N)  dp[i * 3] = min(dp[i * 3], dp[i] + 1);
    }
    cout << dp[N];
}
