#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};

int M, N, K, y1, x1, y2, x2, piece, cnt;
int striped[100][100];
bool visited[100][100];
vector<int> v;

void bfs(int row, int col){
    cnt = 1;
    queue<pair<int, int>> q;
    q.push({row, col});
    visited[row][col] = true;

    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(M <= ny || ny < 0 || N <= nx || nx < 0 ||
            striped[ny][nx] == true || visited[ny][nx] == true) continue;

            q.push({ny, nx});
            visited[ny][nx] = true;
            cnt++;
        }
    }
    v.push_back(cnt);
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N >> K;
    for(int i = 0; i < K; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        for(int i = y1; i < y2; i++)
            for(int j = x1; j < x2; j++)
                striped[i][j] = true;
    }

    for(int i = 0; i < M; i++)
        for(int j = 0; j < N; j++)
            if(striped[i][j] == false && visited[i][j] == false){
                bfs(i, j);
                piece++;
        }

    sort(v.begin(), v.end());
    cout << piece << '\n';
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
}