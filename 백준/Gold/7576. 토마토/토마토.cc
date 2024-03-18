#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int d[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int M, N, cnt;
int map[1001][1001];
int visited[1001][1001];
vector<pair<int, int>> riped;
vector<pair<int, int>> tmp;

void bfs(){
	for(int i = 0; i < riped.size(); i++){
		for(int j = 0; j < 4; j++){
			int row = riped[i].first + d[j][0];
			int col = riped[i].second + d[j][1];
			if(0 <= row && row < N && 0 <= col && col < M && map[row][col] == 0){
				tmp.push_back({row, col});
				map[row][col] = 1;
			}
		}
	}
	riped.clear();
	for(int i = 0; i < tmp.size(); i++)
		riped.push_back(tmp[i]);
	tmp.clear();
	cnt++;
}

int main(void){
	cin >> M >> N;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> map[i][j];
			if(map[i][j] == 1)
				riped.push_back({i, j});
		}
	}

	while(!riped.empty())
		bfs();

	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(map[i][j] == 0)
				cnt = 0;
		}
	}

	cout << cnt - 1;
}