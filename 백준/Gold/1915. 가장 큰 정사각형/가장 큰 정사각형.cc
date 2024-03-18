#include <iostream>
using namespace std;

int N, M;
const int maxi = 1002;
int dp[1002][1002];

void input()
{
	for(int i = 1; i <= N; i++)
	    for(int j = 1; j <= M; j++)
	        scanf("%1d", &dp[i][j]);
}

int min(int i, int j, int k)
{
	if(i >= j)
		if(j >= k)
			return k;
		else
			return j;
	else
		if(i >= k)
			return k;
		else
			return i;
}

void square()
{
	int maxLen = 0;
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= M; j++)
			if(dp[i][j] != 0)
			{
				dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1;
				maxLen = dp[i][j] > maxLen ? dp[i][j] : maxLen;
			}
	cout<<maxLen * maxLen;
}

int main(void)
{
	cin>>N>>M;
	input();
	square();
}