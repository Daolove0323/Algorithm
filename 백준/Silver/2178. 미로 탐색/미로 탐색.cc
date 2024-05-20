#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct pos {
    int y, x, cnt;
};

int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
int n, m;
string s;
bool canMove[100][100], checked[100][100];
queue<pos> q;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        for (int j = 0; j < m; ++j) {
            if (s[j] == '1') canMove[i][j] = true;
            else canMove[i][j] = false;
        }
    }
    
    q.push({0, 0, 0});
    checked[0][0] = true;
    while (!q.empty()) {
        int y = q.front().y;
        int x = q.front().x;
        int cnt = q.front().cnt;
        if (y == n - 1 && x == m - 1) break;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (n <= ny || ny < 0 || m <= nx || nx < 0 || !canMove[ny][nx] || checked[ny][nx])  continue;
            q.push({ny, nx, cnt + 1});
            checked[ny][nx] = true;
        }
    }
    cout << q.front().cnt + 1;
}