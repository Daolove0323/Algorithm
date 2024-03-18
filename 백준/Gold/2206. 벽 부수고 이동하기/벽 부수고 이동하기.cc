#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int N, M, result;
int map[1000][1000];
bool visited[1000][1000][2];

void bfs(){
    queue<vector<int>> q;
    q.push({0, 0, 1, false});
    visited[0][0][0] = true;
    
    while(!q.empty()){
        vector<int> v = q.front();
        q.pop();
        if(v[0] == N - 1 && v[1] == M - 1){
            result = v[2];
            break;
        }
        
        for(int i = 0; i < 4; i++){
            int ny = v[0] + dy[i];
            int nx = v[1] + dx[i];
            if(N <= ny || ny < 0 || M <= nx || nx < 0 ||
            (v[3] == 1 && map[ny][nx] == 1) ||
            (v[3] == 1 && visited[ny][nx][1] == 1) ||
            (v[3] == 0 && visited[ny][nx][0] == 1))
                continue;

            if(v[3] == 0 && map[ny][nx] == 1){
                q.push({ny, nx, v[2] + 1, 1});
                visited[ny][nx][1] = true;
                }
            else{
                q.push({ny, nx, v[2] + 1, v[3]});
                visited[ny][nx][v[3] ? 1 : 0] = true;
                }
        }
    }
}

int main(void){
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            scanf("%1d", &map[i][j]);

    bfs();
    
    if(visited[N - 1][M - 1][0] || visited[N - 1][M - 1][1])
        cout << result;
    else
        cout << -1;
}