#include <iostream>
using namespace std;

int N;
int dp[1000001] = {0, 1, 2};

int main(void){
    cin >> N;
    for(int i = 3; i <= N; i++)
        dp[i] = (dp[i - 2] + dp[i - 1]) % 15746;
    cout << dp[N];
}