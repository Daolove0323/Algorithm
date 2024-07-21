#include <iostream>
using namespace std;

int n, answer;
int arr[1000];
int dp[1000];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    dp[0] = 1;
    for (int i = 1; i < n; ++i) {
        int longest = 1;
        for (int j = 0; j < i; ++j) {
            if (arr[i] > arr[j]) longest = max(longest, dp[j] + 1);
        }
        dp[i] = longest;
    }
    for (int i = 0; i < n; ++i)
        answer = max(answer, dp[i]);
    cout << answer;
}
