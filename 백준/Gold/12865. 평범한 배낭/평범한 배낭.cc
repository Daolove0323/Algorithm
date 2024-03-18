#include <iostream>
using namespace std;

int N, K;
int W[101], V[101];
int dp[101][1000001];

int main(void){
	// 입력
	cin >> N >> K;
	for(int i = 1; i <= N; i++)
		cin >> W[i] >> V[i];

	// 다이나믹 프로그래밍
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= K; j++){
			if(j >= W[i])
				dp[i][j] = max(dp[i-1][j - W[i]] + V[i], dp[i-1][j]);
			else
				dp[i][j] = dp[i-1][j];
		}
	}
	
	cout << dp[N][K];
}