#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dy[] = {-1, 1, 0, 0}, dx[] = {0, 0, -1, 1};
int n, answer1, answer2;
string s;
vector<vector<char>> u, v;
vector<vector<bool>> w;

void bfs(int r, int c, char color, vector<vector<char>>& v) {
    queue<pair<int, int>> q;
    q.push({r, c});
    w[r][c] = true;
    
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (!(0 <= ny && ny < n) || !(0 <= nx && nx < n) || w[ny][nx] || v[ny][nx] != color) continue;
            q.push({ny, nx});
            w[ny][nx] = true;
        }
    }
}

int main () {
    cin >> n;
    u.resize(n); v.resize(n);
    w.resize(n, vector<bool>(n, false));
    for (int i = 0; i < n; ++i) {
        cin >> s;
        for (auto c : s) {
            u[i].push_back(c);
            if (c == 'G') v[i].push_back('R');
            else v[i].push_back(c);
        }
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (w[i][j]) continue;
            bfs(i, j, u[i][j], u);  ++answer1;
        }
    }
    w.clear();
    w.resize(n, vector<bool>(n, false));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (w[i][j]) continue;
            bfs(i, j, v[i][j], v);  ++answer2;
        }
    }
    cout << answer1 << " " << answer2;
}
