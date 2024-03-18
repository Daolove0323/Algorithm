#include <iostream>
#include <vector>
using namespace std;

int T, N, K, W;
int D[1001], dp[1001];
vector<pair<int, int>> V;

void initDp(int len){
	for(int i = 1; i <= len; i++)
		dp[i] = -1;
}

int retTime(int idx){
	int max = 0;
	for(int i = 1, tmp = 0; i <= K; i++){
		if(V[i].second == idx){
			if(dp[V[i].first] == -1)
				tmp = retTime(V[i].first);
			else
				tmp = dp[V[i].first];

			if(tmp > max)
				max = tmp;
		}
	}
	return dp[idx] = D[idx] + max;
}

int main(void){
	cin >> T;

	for(int i = 1; i <= T; i++){
	cin >> N >> K;
	
	for(int i = 1; i <= N; i++)
		cin >> D[i];

	V.push_back(make_pair(0, 0));
	for(int i = 1; i <= K; i++){
		pair<int, int> p;
		cin >> p.first >> p.second;
		V.push_back(p);
	}

	cin >> W;
	initDp(N);

	cout << retTime(W) << endl;
	
	V.clear();
	}
}