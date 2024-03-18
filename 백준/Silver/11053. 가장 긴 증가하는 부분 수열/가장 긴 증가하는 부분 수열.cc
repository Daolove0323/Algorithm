#include <iostream>
using namespace std;

int MAX = 1, N;
int arr[1001];
int dp[1001];

int main(void){
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> arr[i];

    dp[1] = 1;
    for(int i = 2; i <= N; i++){
        int tmp = 0;
        for(int j = i - 1; j >= 0; j--){
            if(arr[j] < arr[i] && tmp < dp[j])
                tmp = dp[j];
        }
        dp[i] = tmp + 1;
        MAX = MAX < dp[i] ? dp[i] : MAX;
    }
    cout << MAX;
}