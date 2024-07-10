#include <iostream>
#include <queue>
using namespace std;

struct pos {
    int z, y, x;
};

int dx[] = {-1, 1, 0, 0, 0, 0}, dy[] = {0, 0, -1, 1, 0, 0}, dz[] = {0, 0, 0, 0, -1, 1};
bool completed;
int h, m ,n, day;
int arr[101][101][101];
queue<pos> ripe;

bool passDay() {
    bool changed = false;
    queue<pos> next;
    while (!ripe.empty()) {
        pos p = ripe.front();
        ripe.pop();
        for (int i = 0; i < 6; ++i) {
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];
            int nz = p.z + dz[i];
            if (!(0 <= nz && nz < h) || !(0 <= ny && ny < m) || !(0 <= nx && nx < n) || arr[nz][ny][nx] != 0) continue;
            next.push({nz, ny, nx});
            arr[nz][ny][nx] = 1;
            changed = true;
        }
    }
    ripe = next;
    if (changed) ++day;
    return changed;
}

bool isAllRipe() {
    for (int i = 0; i < h; ++i)
        for (int j = 0; j < m; ++j)
            for (int k = 0; k < n; ++k)
                if (arr[i][j][k] == 0)
                    return false;
    return true;
}

int main() {
    cin >> n >> m >> h;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < n; ++k) {
                cin >> arr[i][j][k];
                if (arr[i][j][k] == 1) {
                    ripe.push({i, j ,k});
                }
            }
        }
    }
    
    while(!completed) {
        completed = true;
        if (passDay())
            completed = false;
    }
    
    if (isAllRipe()) cout << day;
    else cout << -1;
}
