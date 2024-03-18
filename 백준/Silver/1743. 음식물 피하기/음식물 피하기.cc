#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int N, M, K, result;
bool aisle[101][101];
bool checked[101][101];
vector<pair<int, int>> v(10000);

// bfs
void bfs(int r, int c) {
    int val = 1;
    queue<pair<int, int>> q;
    q.push({r, c});
    checked[r][c] = true;

    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;

        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(N < ny || ny <= 0 || M < nx || nx <= 0 || aisle[ny][nx] == false || checked[ny][nx] == true) continue;
            q.push({ny, nx});
            checked[ny][nx] = true;
            val++;
        }
        q.pop();
    }

    result = result < val ? val : result;
}

int main(void) {

    // 입력
    cin >> N >> M >> K;
    for(int i = 0; i < K; i++) {
        int n, m;
        cin >> n >> m;
        v[i] = {n, m};
        aisle[n][m] = true;
    }

    // bfs
    for(int i = 0; i < K; i++) {
        if(checked[v[i].first][v[i].second]) continue;
        bfs(v[i].first, v[i].second);
    }
    
    cout << result;
}