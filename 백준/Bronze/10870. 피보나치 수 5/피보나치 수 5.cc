#include <iostream>
using namespace std;

int dp[21];
int n;

int main(void)
{
	dp[0] = 0;
	dp[1] = 1;
	
	for(int i = 2; i <= 20; i++)
		dp[i] = dp[i - 2] + dp[i - 1];

	cin >> n;
	cout << dp[n];
}