#include <iostream>
using namespace std;

int arr[100001];
int dp[100001];
int maxSum;

int main(void)
{
	int N, input;
	cin>>N;
	for(int i = 1; i <= N; i++)
	{
		cin>>input;
		arr[i] = input;
	}

	maxSum = arr[1];
	for(int i = 1; i <=N; i++)
	{
		int ans = dp[i-1] + arr[i];
		dp[i] = arr[i] < ans ? ans : arr[i];
		maxSum = maxSum < dp[i] ? dp[i] : maxSum;
	}
	
	cout<<maxSum;
}
