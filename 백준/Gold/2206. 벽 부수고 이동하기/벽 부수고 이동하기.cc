#include <iostream>
#include <queue>
#include <cstring>
#define USE 1
#define NOT_USE 0
#define INF 0x3f3f3f3f
using namespace std;

struct info {
    int y, x, use;
};

int dy[] = {-1, 1, 0, 0}, dx[] = {0, 0, -1, 1};
string input;
int n, m;
int arr[1000][1000];
int cnt[2][1000][1000];
queue<info> q;

int main () {
    memset(cnt, INF, sizeof(int) * 2 * 1000 * 1000);
    cin >> n >> m;
    for (int i = 0 ; i < n; ++i) {
        cin >> input;
        for (int j = 0; j < m; ++j)
            arr[i][j] = input[j] - '0';
    }
    
    q.push({0, 0, NOT_USE});
    cnt[NOT_USE][0][0] = cnt[USE][0][0] =  1;
    
    while (!q.empty()) {
        int y = q.front().y;
        int x = q.front().x;
        bool use = q.front().use;
        if (y == n && x == m) break;
        q.pop();
        
        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (!(0 <= ny && ny < n) || !(0 <= nx && nx < m)) continue; // 범위 밖인 경우
            if (arr[ny][nx] == 1 && use == USE) continue;   // 벽에 막히는 경우
            if (cnt[NOT_USE][ny][nx] <= cnt[use][y][x] + 1) continue; // 부수지않았을 때 더 가까운 경우
            if (use == USE && cnt[USE][ny][nx] <= cnt[USE][y][x] + 1) continue; // 부쉈을  때 더 가까운 경우
            if (arr[ny][nx] == 1) { // 벽인 경우
                q.push({ny, nx, USE});  // 부수기
                cnt[USE][ny][nx] = cnt[NOT_USE][y][x] + 1;  // 부순 경우 기록 갱신
            } else {    // 빈공간인 경우
                q.push({ny, nx, use});  // 통과
                if (use == USE) cnt[USE][ny][nx] = cnt[use][y][x] + 1;  // 부쉈는 경우 기록 갱신
                else {  // 부수지 않은 경우
                    cnt[NOT_USE][ny][nx] = cnt[NOT_USE][y][x] + 1;   // 부수지 않은 경우 기록 갱신
                    cnt[USE][ny][nx] = min(cnt[USE][ny][nx], cnt[use][y][x] + 1);   // 부순 경우 기록 갱신
                    
                }
            }
        }
    }
    
    if (cnt[NOT_USE][n - 1][m - 1] == INF && cnt[USE][n - 1][m - 1] == INF) cout << -1;
    else cout << min(cnt[NOT_USE][n - 1][m - 1], cnt[USE][n - 1][m - 1]);
}
