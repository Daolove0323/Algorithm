#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int T, M, N, K, bug;
int d[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

void bfs(bool arr[][50], int i, int j){
	queue<pair<int, int>> q;
	pair<int, int> p = make_pair(i, j);
	q.push(p);

	while(!q.empty()){
		p = q.front();
		q.pop();
		for(int n = 0; n < 4; n++){
			pair<int, int> tmp = make_pair(p.first + d[n][0], p.second + d[n][1]);
			if(arr[tmp.first][tmp.second] == true && 
			0 <= tmp.first && tmp.first < M && 0 <= tmp.second && tmp.second < N){
				q.push(tmp);
				arr[tmp.first][tmp.second] = false;
			 }
		}
	}
}

int main(void){
	cin >> T;
	while(T--){
		bool arr[50][50] = {};
		bug = 0;
		cin >> M >> N >> K;
		for(int i = 0; i < K; i++){
			int x, y;
			cin >> x >> y;
			arr[x][y] = true;
		}
		
		for(int i = 0; i < M; i++){
			for(int j = 0; j < N; j++){
				if(arr[i][j] == true){
					bfs(arr, i, j);
					bug++;
					}
			}
		}
		cout << bug << endl;
	}
}