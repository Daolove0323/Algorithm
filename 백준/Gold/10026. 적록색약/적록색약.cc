#include <iostream>
#include <queue>
using namespace std;

enum STATE {RED, GREEN, BLUE};
pair<int, int> dir[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int normal[100][100], disabled[100][100];
bool normal_checked[100][100], disabled_checked[100][100];
int normal_count, disabled_count, N;

void normal_bfs(int row, int col){
	queue<pair<int, int>> q;
	q.push({row, col});

	while(!q.empty()){
		pair<int, int> p = q.front();
		int normal_state = normal[p.first][p.second];
		normal_checked[p.first][p.second] = true;
		q.pop();
		
		for(int i = 0; i < 4; i++){
			int ny = p.first + dir[i].first;
			int nx = p.second + dir[i].second;
			if(N <= nx || nx < 0 || N <= ny || ny < 0 ||
			normal_checked[ny][nx] == true || normal[ny][nx] != normal_state) continue;
			q.push({ny, nx});
			normal_checked[ny][nx] = true;
		}
	}
}

void disabled_bfs(int row, int col){
	queue<pair<int, int>> q;
	q.push({row, col});

	while(!q.empty()){
		pair<int, int> p = q.front();
		int disabled_state = disabled[p.first][p.second];
		disabled_checked[p.first][p.second] = true;
		q.pop();
		
		for(int i = 0; i < 4; i++){
			int ny = p.first + dir[i].first;
			int nx = p.second + dir[i].second;
			if(N <= nx || nx < 0 || N <= ny || ny < 0 ||
			disabled_checked[ny][nx] == true || disabled[ny][nx] != disabled_state) continue;
			q.push({ny, nx});
			disabled_checked[ny][nx] = true;
		}
	}
}

int main(void){
	cin >> N;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++){
			char c;
			cin >> c;
			if(c == 'R')
				normal[i][j] = disabled[i][j] = RED;
			else if(c == 'G'){
				normal[i][j] = GREEN;
				disabled[i][j] = RED;
				}
			else
				normal[i][j] = disabled[i][j] = BLUE;
		}

		
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(normal_checked[i][j] == true) continue;
			normal_bfs(i, j);
			normal_count++;
		}
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(disabled_checked[i][j] == true) continue;
			disabled_bfs(i, j);
			disabled_count++;
		}
	}

	cout << normal_count << " " << disabled_count;
}
