#include <iostream>
#include <string>
using namespace std;

int max(int n1, int n2)
{
	if(n1>n2)
		return n1;
	else
		return n2;
}

int main(void)
{
	int dp[1001][1001];
	string s1, s2;
	cin>>s1>>s2;
	
	for(int i = 0; i <= s1.size(); i++)
		dp[i][0] = 0;
	for(int i = 0; i <= s2.size(); i++)
		dp[0][i] = 0;

	for(int row = 1; row <= s1.size(); row++)
	{
		for(int col = 1; col <= s2.size(); col++)
		{
			if(s1[row-1] == s2[col-1])
				dp[row][col] = dp[row-1][col-1] + 1;
			else
				dp[row][col] = max(dp[row-1][col], dp[row][col-1]);
		}
	}

	// for(int i = 0; i <= s1.size(); i++)
	// {
	// 	for(int j = 0; j <= s2.size(); j++)
	// 	{
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	cout<<dp[s1.size()][s2.size()];


}