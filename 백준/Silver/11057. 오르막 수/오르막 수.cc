#include <iostream>
using namespace std;

int dp[10];
int N, sum;

int main(void) {
    cin >> N;
    for(int i = 0; i < 10; i++) dp[i] = 1;

    // dp
    for(int i = 1; i < N; i++) {
        for(int j = 9; j >= 0; j--) {
            for(int k = 0; k < j; k++) {
                dp[j] += dp[k];
                dp[j] %= 10007;
            }
        }
    }

    for(int i = 0; i < 10; i++)
        sum += dp[i];

    cout << sum % 10007;
}