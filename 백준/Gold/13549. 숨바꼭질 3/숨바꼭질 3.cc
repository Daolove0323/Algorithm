#include <iostream>
#include <queue>
#define INF 1e9
using namespace std;

int cur, target;
int dp[100001];
queue<int> q;

bool isValid(int n) {
    return (0 <= n && n <= 100000);
}

int main() {
    fill_n(dp, 100001, INF);
    cin >> cur >> target;
    dp[cur] = 0;
    q.push(cur);
    while (!q.empty()) {
        int n = q.front();
        if (n == target) break;
        q.pop();
        if (isValid(n - 1) && dp[n - 1] > dp[n] + 1) {q.push(n - 1); dp[n - 1] = dp[n] + 1;}
        if (isValid(n + 1) && dp[n + 1] > dp[n] + 1) {q.push(n + 1); dp[n + 1] = dp[n] + 1;}
        if (isValid(n * 2) && dp[n * 2] > dp[n]) {q.push(n * 2); dp[n * 2] = dp[n];}
    }
    cout << dp[target];
}
