#include <iostream>
using namespace std;

int N;
int cost[3][1001], dp[3][1001];

void func(int i){
    dp[0][i] = min(dp[1][i - 1], dp[2][i - 1]) + cost[0][i];
    dp[1][i] = min(dp[0][i - 1], dp[2][i - 1]) + cost[1][i];
    dp[2][i] = min(dp[0][i - 1], dp[1][i - 1]) + cost[2][i];
}

int main(void){
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> cost[0][i] >> cost[1][i] >> cost[2][i];
    dp[0][0] = cost[0][0], dp[0][1] = cost[0][1], dp[0][2] = cost[0][2];
    for(int i = 1; i <= N; i++) func(i);
    cout << min(min(dp[0][N], dp[1][N]), dp[2][N]);
}