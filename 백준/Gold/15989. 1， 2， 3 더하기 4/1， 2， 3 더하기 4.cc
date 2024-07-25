#include <iostream>
using namespace std;

int T, N;
int dp[10001];

void init() {
    dp[1] = 1; dp[2] = 2; dp[3] = 3;
    for (int i = 4; i <= 10000; ++i)
        dp[i] = dp[i - 3] + i / 2 + 1;
}

int main() {
    init();
    cin >> T;
    while (T--) {
        cin >> N;
        cout << dp[N] << '\n';
    }
}
