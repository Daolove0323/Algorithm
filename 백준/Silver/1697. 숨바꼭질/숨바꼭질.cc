#include <iostream>
#include <queue>
using namespace std;

const int maxIdx = 200001;

int N, K;
int dp[maxIdx];

void bfs(){
	queue<int> q;
	q.push(N);

	while(true){
		int tmp = q.front();
		if(tmp == K) break;
		q.pop();

		if(dp[tmp + 1] == 0 && 0 <= tmp + 1 && tmp + 1 < maxIdx){
		q.push(tmp + 1);
		dp[tmp + 1] = dp[tmp] + 1;
		}

		if(dp[tmp - 1] == 0 && 0 <= tmp -1 && tmp -1 < maxIdx){
		q.push(tmp - 1);
		dp[tmp - 1] = dp[tmp] + 1;
		}

		if(dp[tmp * 2] == 0 && 0 <= tmp * 2 && tmp * 2 < maxIdx){
		q.push(tmp * 2);
		dp[tmp * 2] = dp[tmp] + 1;
		}
	}
}

int main(void){
	cin >> N >> K;
	bfs();
	cout << dp[K];
}