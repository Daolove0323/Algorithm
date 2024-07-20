#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int dy[] = {-1, 1, 0, 0}, dx[] = {0, 0, -1, 1};

int n, m;
int matured[1000][1000];
queue<pair<int, int>> q;

int getMaxDay() {
    int val = 0;
    bool allMatured = true;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (matured[i][j] == 0) return -1;
            else if (matured[i][j] == -1) continue;
            else val = max(val, matured[i][j]);
    return val - 1;
}

void bfs() {
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (!(0 <= ny && ny < n) || !(0 <= nx && nx < m) || matured[ny][nx] != 0) continue;
            q.push({ny, nx});
            matured[ny][nx] = matured[y][x] + 1;
        }
    }
}

int main() {
    cin >> m >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> matured[i][j];
    
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (matured[i][j] == 1) q.push({i, j});
    bfs();
    
    cout << getMaxDay();
}
