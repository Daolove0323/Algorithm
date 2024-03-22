#include <string>
#include <vector>
using namespace std;

int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    for(int i = 0; i < 4; ++i) {
        int ny = h + dy[i], nx = w + dx[i];
        if(board.size() <= ny || ny < 0 || board[0].size() <= nx || nx < 0) continue;
        if(board[ny][nx] == board[h][w]) ++answer;
    }
    return answer;
}