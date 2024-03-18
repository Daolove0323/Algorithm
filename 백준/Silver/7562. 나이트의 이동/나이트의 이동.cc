#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

pair<int, int> dir[8] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
int T, I;
pair<int, int> from, to;
int map[300][300];

void bfs(){
	queue<pair<int, int>> q;
	q.push({from.first, from.second});
	map[from.first][from.second] = 0;
	
	while(!q.empty()){
		pair<int, int> p = q.front();
		q.pop();
		
		for(int i = 0; i < 8; i++){
			int toY = p.first + dir[i].first;
			int toX = p.second + dir[i].second;
			
			if(I <= toY || toY < 0 || I <= toX || toX < 0 || map[toY][toX] != -1) continue;
			q.push({toY, toX});	
			map[toY][toX] = map[p.first][p.second] + 1;
		}
	}
}

int main(void){
	cin >> T;
	while(T--){
		cin >> I >> from.first >> from.second >> to.first >> to.second;
		memset(map, -1, sizeof(map));
		bfs();
		cout << map[to.first][to.second] << '\n';
	}
}