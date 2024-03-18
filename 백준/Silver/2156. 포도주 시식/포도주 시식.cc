#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[10000];
int dp[10000][3];

int main(void){
    cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];
    
    dp[0][0] = 0; dp[0][1] = dp[0][2] = arr[0];
    dp[1][0] = arr[0] + arr[1]; dp[1][1] = dp[1][2] = arr[1];
    dp[2][0] = arr[1] + arr[2]; dp[2][1] = arr[0] + arr[2]; dp[2][2] = arr[2];
    
    for(int i = 3; i < N; i++){
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + arr[i];
        dp[i][1] = max({dp[i - 2][0], dp[i - 2][1], dp[i - 2][2]}) + arr[i];
        dp[i][2] = max({dp[i - 3][0], dp[i - 3][1], dp[i - 3][2]}) + arr[i];
    }
    
    cout << max({dp[N - 1][0], dp[N - 1][1], dp[N - 2][0]});
    
}
