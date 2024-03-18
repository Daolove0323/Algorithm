#include <iostream>
#include <array>
#include <utility>
using namespace std;

int N, K, cnt = 0;
bool infected[101] = {false, true};
bool adj[101][101];

void dfs(int n){
	for(int i = 1; i <= N; i++){
		if(adj[n][i] == true && infected[i] == false){
			infected[i] = true;
			cnt++;
			dfs(i);
		}
	}
}

int main(void){
	cin >> N >> K;
	for(int i = 0; i < K; i++){
		int n1, n2;
		cin >> n1 >> n2;
		adj[n1][n2] = adj[n2][n1] = true;
	}

	dfs(1);
	cout << cnt;
}