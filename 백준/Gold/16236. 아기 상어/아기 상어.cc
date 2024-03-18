#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int N, s, sharkSize, xp, result;
pair<int, int> pos;
int map[20][20];
bool visited[20][20];

bool search(){
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            if(0 < map[i][j] && map[i][j] < sharkSize)
                return true;
    return false;
}

bool bfs(){
    sharkSize = 2;
    queue<pair<int, int>> q;
    q.push(pos);
    visited[pos.first][pos.second] = true;
    if(!search()) return true;

    while(!q.empty()){
        int loop = q.size();    
        s++;
        bool eatable = false;
        int toY = 20, toX = 20;
        
        while(loop--){
            int y = q.front().first;
            int x = q.front().second;
            visited[y][x] = true;
            q.pop();

            for(int i = 0; i < 4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(N <= ny || ny < 0 || N <= nx || nx < 0 ||
                   visited[ny][nx] == true || sharkSize < map[ny][nx]) continue;
                if(0 < map[ny][nx] && map[ny][nx] < sharkSize){
                    eatable = true;
                    if(ny < toY || (ny == toY && nx < toX)){
                        toY = ny;
                        toX = nx;
                    }
                continue;
                }
                q.push({ny, nx});
                visited[ny][nx] = true;
            }
        }
            if(eatable){
            map[toY][toX] = 0;
            xp++;
            result = s;
            memset(visited, false, sizeof(visited));
            if(xp == sharkSize){
                xp = 0;
                sharkSize++;
            }
            if(!search()) return true;
            while(!q.empty()) q.pop();
            q.push({toY, toX});
        }
    }
    return false;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++){
            cin >> map[i][j];
            if(map[i][j] == 9){
                map[i][j] = 0;
                pos = {i, j};
                }
        }    

    if(bfs()) cout << s;
    else cout << result;
    
}

