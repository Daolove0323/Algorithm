#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int dy[] = {-1, 1, 0, 0}, dx[] = {0, 0, -1, 1};
int n, g_cnt;
string s;
int map[25][25];
bool check[25][25];
vector<int> answer;

void bfs(int r, int c) {
    int cnt = 1;
    queue<pair<int ,int>> q;
    q.push({r, c});
    check[r][c] = true;
    
    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (n <= ny || ny < 0 || n <= nx || nx < 0 || map[ny][nx] == 0 || check[ny][nx]) continue;
            q.push({ny, nx});
            check[ny][nx] = true;
            ++cnt;
        }
    }
    answer.push_back(cnt);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        for (int j = 0; j < n; ++j) {
            map[i][j] = s[j] - '0';
        }
    }
        
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (map[i][j] && !check[i][j]) {
                bfs(i, j);
                ++g_cnt;
            }
            
    sort(answer.begin(), answer.end());
    cout << g_cnt << '\n';
    for (auto i : answer)
        cout << i << '\n';
}