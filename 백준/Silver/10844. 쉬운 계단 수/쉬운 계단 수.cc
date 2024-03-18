#include <iostream>
#include <cstring>
using namespace std;

int N;
long long sum;
int arr[10] = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1};
int dp[10] = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1};

int main(void){
    cin >> N;
    for(int i = 1; i < N; i++){
        memset(dp, 0, sizeof(dp));
        for(int j = 0; j < 10; j++){
            if(1 <= j && j <= 8){
                dp[j - 1] += arr[j] % 1000000000;
                dp[j + 1] += arr[j] % 1000000000;
            }
            else if(j == 0)
                dp[j + 1] += arr[j] % 1000000000;
            else if(j == 9)
                dp[j - 1] += arr[j] % 1000000000;
        }
        for(int k = 0; k < 10; k++) arr[k] = dp[k];
    }
    for(int i = 0; i < 10; i++) sum += dp[i];
    cout << sum % 1000000000;
}