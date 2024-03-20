#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct Move {
    int y, x, cnt;
};
int answer = -1;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool isVisited[101][101];

int solution(vector<vector<int> > maps)
{
    queue<Move> q;
    q.push({0, 0, 1});
    isVisited[0][0] = true;
    while(!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int cnt = q.front().cnt;
        q.pop();
        if(y == maps.size() - 1 && x == maps[0].size() - 1) {
            answer = cnt;
            return answer;
        }
        for(int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(maps.size() <= ny || ny < 0
               || maps[0].size() <= nx || nx < 0
               || isVisited[ny][nx]
               || maps[ny][nx] == 0) continue;
            q.push({ny, nx, cnt + 1});
            isVisited[ny][nx] = true;
        }
    }
    return answer;
}