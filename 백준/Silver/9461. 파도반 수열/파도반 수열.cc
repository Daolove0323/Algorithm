#include <iostream>
using namespace std;

int T, N;
long long dp[101] = {0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9};

int main(void){
	for(int i = 11; i <= 100; i++)
		dp[i] = dp[i - 1] + dp[i - 5];
	cin >> T;
	while(T--){
		cin >> N;
		cout << dp[N] << endl;
	}
    
}