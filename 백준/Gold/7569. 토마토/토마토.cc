#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int ripe[6][3] = {{-1, 0, 0}, {1, 0, 0}, {0, -1, 0}, {0, 1, 0}, {0, 0, -1}, {0, 0, 1}};

int M, N, H;
int day = -1;
int box[100][100][100]; // -1 : 빈 / 0 : 안익은 / 1 : 익은
vector<vector<int>> v;

bool allRiped(){
    for(int i = 0; i < H; i++)
        for(int j = 0; j < N; j++)
            for(int k = 0; k < M; k++)
                if(box[i][j][k] == 0)
                    return false;
    return true;
}

void bfs(){
    queue<vector<int>> q;
    for(int i = 0; i < v.size(); i++)
        q.push({v[i][0], v[i][1], v[i][2]});
    
    while(!q.empty()){
        int repeat = q.size();
        bool changed = false;

        while(repeat--){
            vector<int> tmp = q.front();
            for(int i = 0; i < 6; i++){
                int nz = tmp[0] + ripe[i][0];
                int ny = tmp[1] + ripe[i][1];
                int nx = tmp[2] + ripe[i][2];
                if(H <= nz || nz < 0 || N <= ny || ny < 0 || M <= nx || nx < 0 ||
                    box[nz][ny][nx] != 0) continue;

            q.push({nz, ny, nx});
            box[nz][ny][nx] = 1;
            changed = true;
            } 
            q.pop();
        } 
        day++;
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    cin >> M >> N >> H;
    for(int i = 0; i < H; i++)
        for(int j = 0; j < N; j++)
            for(int k = 0; k < M; k++){
                cin >> box[i][j][k];
                if(box[i][j][k] == 1)
                    v.push_back({i, j, k});
            }
                
    bfs();
    if(allRiped()) cout << day;
    else cout << -1;
}