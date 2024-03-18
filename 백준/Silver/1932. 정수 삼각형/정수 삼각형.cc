#include <iostream>
using namespace std;

int n;
int arr[501][501], dp[501][501];

void func(int c, int i){
    dp[c + 1][i] = max(dp[c + 1][i], dp[c][i] + arr[c + 1][i]);
    dp[c + 1][i + 1] = max(dp[c + 1][i + 1], dp[c][i] + arr[c + 1][i + 1]);
}

int maxIs(){
    int MAX = 0;
    for(int i = 1; i <= n; i++)
        MAX = max(MAX, dp[n][i]);
    return MAX;
}

int main(void){
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= i; j++)
            cin >>arr[i][j];

    dp[1][1] = arr[1][1];
    for(int c = 1; c < n; c++)
        for(int i = 1; i <= c; i++)
            func(c, i);
    cout << maxIs();
}