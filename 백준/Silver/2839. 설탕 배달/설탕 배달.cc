#include <iostream>
using namespace std;

int dp[5001];
int N;

int main(void)
{
	// 3 <= N <= 5000
	dp[3] = dp[5] = 1;
	for(int i = 3; i <= 5000; i++)
	{
		if(dp[i-3] != 0 && (dp[i] > dp[i-3] + 1 || dp[i] == 0))
			dp[i] = dp[i-3] + 1;
		
		if(dp[i-5] != 0 && (dp[i] > dp[i-5] + 1 || dp[i] == 0))
			dp[i] = dp[i-5] + 1;
	}

	cin >> N;
	if(dp[N] == 0)
		cout << -1;
	else
		cout << dp[N];
}