#include <iostream>
using namespace std;

int dp[13];
int T, n;

int main(void)
{
	dp[0] = 1;
	for(int i = 0; i <= 9; i++)
	{
		dp[i + 1] += dp[i];
		dp[i + 2] += dp[i];
		dp[i + 3] += dp[i];
	}
	
	cin >> T;
	while(T--)
	{
		cin >> n;	
		cout << dp[n] << endl;
	}
}