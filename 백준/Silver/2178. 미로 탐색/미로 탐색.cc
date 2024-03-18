#include <iostream>
#include <queue>
#include <utility>
using namespace std;

pair<int, int> direction[4] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
int N, M;
int maze[100][100];
bool visited[100][100];

void bfs(int i, int j){
	queue<pair<int, int>> q;
	pair<int, int> p = make_pair(i, j);
	q.push(p);
	maze[i][j] = 1;
	visited[i][j] = true;

	while(!q.empty()){
		p = q.front();
		q.pop();
		for(int i = 0; i < 4; i++){
			pair<int, int> tmp = make_pair(p.first + direction[i].first, p.second + direction[i].second);
			if(tmp.first < 0 || N <= tmp.first
			|| tmp.second < 0 || M <= tmp.second
			|| maze[tmp.first][tmp.second] == 0 || visited[tmp.first][tmp.second] == true)
				continue;
			q.push(tmp);
			visited[tmp.first][tmp.second] = true;
			maze[tmp.first][tmp.second] = maze[p.first][p.second] + 1;
		}
	}

}

int main(void)
{
	cin >> N >> M;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			int n;
			scanf("%1d", &n);
			maze[i][j] = n;
		}
	}
	bfs(0, 0);
	cout << maze[N-1][M-1];
}