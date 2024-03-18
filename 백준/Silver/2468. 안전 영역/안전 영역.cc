#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int map[101][101];
bool after[101][101];
bool visited[101][101];
int N, result, cnt;

void init(int h){
	memset(after, false, sizeof(after));
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			if(map[i][j] > h)
				after[i][j] = true;

	memset(visited, false, sizeof(visited));
	cnt = 0;
}

void bfs(int i, int j){
	queue<pair<int, int>> q;
	q.push({i, j});
	visited[i][j] = true;

	while(!q.empty()){
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for(int i = 0; i < 4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny < 0 || ny >= N || nx < 0 || nx >= N)	continue;
			if(after[ny][nx] == true && visited[ny][nx] == false){
				q.push({ny, nx});
				visited[ny][nx] = true;
			}
		}		
	}
}

void solution(){
	for(int h = 0; h <= 100; h++){
		init(h);
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				if(after[i][j] == true && visited[i][j] == false){
					bfs(i, j);
					cnt++;
				}
			}
		}
		result = max(result, cnt);
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> N;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			cin >> map[i][j];
	solution();
	cout << result;
}