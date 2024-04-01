#include <string>
#include <vector>
using namespace std;

long long dp[2002];
long long solution(int n) {
    dp[0] = 1;
    for(int i = 0; i <= n - 1; ++i) {
        dp[i + 1] = (dp[i] + dp[i + 1]) % 1234567;
        dp[i + 2] = (dp[i] + dp[i + 2]) % 1234567;
    }
    return dp[n];
}