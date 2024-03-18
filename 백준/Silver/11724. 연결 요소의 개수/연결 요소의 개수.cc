#include <iostream>
#include <vector>
using namespace std;

int N, M, u, v, cnt;
vector<int> adj[1001];
bool visited[1001];

void dfs(int idx){
	for(int i = 0; i < adj[idx].size(); i++){
		if(visited[adj[idx][i]] == true) continue;
		visited[adj[idx][i]] = true;
		dfs(adj[idx][i]);
	}
}  

int main(void){
	cin >> N >> M;
	for(int i = 0; i < M; i++){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for(int i = 1; i <= N; i++){
		if(visited[i] == true) continue;
		dfs(i);
		cnt++;
	}

	cout << cnt;
}