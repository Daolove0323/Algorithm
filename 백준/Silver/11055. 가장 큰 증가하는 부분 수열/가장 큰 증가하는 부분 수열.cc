#include <iostream>
using namespace std;

int N, sum;
int arr[1002];
int dp[1002];

int main(void) {
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
        dp[i] = arr[i];
    }

    dp[1] = arr[1];
    for(int i = 1; i <= N; i++)
        for(int j = 0; j < i; j++)
            if(arr[i] > arr[j])
                dp[i] = max(dp[i], dp[j] + arr[i]);
    
    for(int i = 0; i <= N; i++)
        sum = max(sum, dp[i]);
    cout << sum;
}