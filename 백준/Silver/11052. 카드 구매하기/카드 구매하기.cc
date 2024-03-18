#include <iostream>
#include <algorithm>
using namespace std;

int N;
int p[10002];
int dp[1001];


int main(void) {
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> p[i];

    for(int i = 0; i <= N; i++)
        for(int j = 1; j <= N - i; j++)
            dp[i + j] = max(dp[i + j], dp[i] + p[j]);

    cout << dp[N];
}