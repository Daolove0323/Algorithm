#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[302];
long dp[2][302];

int main(void){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    
    dp[0][1] = dp[1][1] = arr[1];
    dp[0][2] = arr[2];
    for(int i = 0; i < n; i++){        
        dp[1][i + 1] = dp[0][i] + arr[i + 1];
        dp[0][i + 2] = max(dp[0][i], dp[1][i]) + arr[i + 2];
    }
    
    cout << max(dp[0][n], dp[1][n]);
}