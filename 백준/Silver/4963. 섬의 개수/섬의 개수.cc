#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int dx[3] = {-1, 0, 1};
int dy[3] = {-1, 0, 1};
int arr[50][50];
int w, h, cnt;

void bfs(int row, int  col){
	queue<pair<int, int>> q;
	pair<int, int> p = {row, col};
	q.push(p);

	while(!q.empty()){
		p = q.front();
		q.pop();
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
				row = p.first + dx[i];
				col = p.second + dy[j];
				if(0 <= row && row < h && 0 <= col && col < w && arr[row][col] == 1 && (i != 1 || j != 1)){
					q.push({row, col});
					arr[row][col] = 0;
				}
			}
		}
	}
}

int main(void){
	// 입력
	cin >> w >> h;
	while(w != 0 && h != 0){
		for(int i = 0; i < h; i++)
			for(int j = 0; j < w; j++){
				cin >> arr[i][j];
			}

	// bfs
		for(int i = 0; i < h; i++)
			for(int j = 0; j < w; j++)
				if(arr[i][j] == 1){
					bfs(i, j);
					cnt++;
				}

	// 출력
		cout <<  cnt << endl;
		cnt = 0;

		cin >> w >> h;
	}
}