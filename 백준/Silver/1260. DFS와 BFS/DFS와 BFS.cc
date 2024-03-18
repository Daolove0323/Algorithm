#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, V;
bool visited[1001];
vector<int> edge[1001];

void dfs(int idx){
	if(visited[idx] == true) return;
	visited[idx] = true;
	cout << idx <<" ";
	for(vector<int>::iterator iter = edge[idx].begin(); iter != edge[idx].end(); iter++){
		dfs(*iter);
	}
}

void bfs(int idx){
	queue<int> q;
	q.push(idx);
	visited[idx] = true;

	while(!q.empty()){
		int tmp = q.front();
		q.pop();
		cout << tmp << " ";
		for(vector<int>::iterator iter = edge[tmp].begin(); iter != edge[tmp].end(); iter++){
			if(visited[*iter] == true) continue;
			q.push(*iter);
			visited[*iter] = true;
		}
	}
}

int main(void)
{
	cin >> N >> M >> V;
	for(int i = 0; i < M; i++){
		int v1, v2;
		cin >> v1 >> v2;
		edge[v1].push_back(v2);
		edge[v2].push_back(v1);
	}
	for(int i = 1; i <= N; i++)
		sort(edge[i].begin(), edge[i].end());

	dfs(V);
	cout << endl;
	for(int i = 1; i <= N; i++)
		visited[i] = false;
	bfs(V);
}
