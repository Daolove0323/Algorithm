#include <iostream>
using namespace std;

int n, k;
int dp[100001];
int w[100], v[100];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> w[i] >> v[i];
    
    for (int i = 0; i < n; ++i) {
        for (int j = k; j >= 0; --j) {
            if (j - w[i] < 0) break;
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    cout << dp[k];
}
