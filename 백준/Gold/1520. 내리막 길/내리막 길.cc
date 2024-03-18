#include <iostream>
#include <cstring>
using namespace std;

int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};

int M, N;
int board[501][501];
int dp[501][501];

void solution(int y, int x) {
    if(dp[y][x] != -1) return;
    
    int val = 0;
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(M <= ny || ny < 0 || N <= nx || nx < 0) continue;
        if(board[y][x] < board[ny][nx]) {
            solution(ny, nx);
            val += dp[ny][nx];
        }
    }
    
    dp[y][x] = val;
}

int main(void) {
    memset(dp, -1, sizeof(int) * 501 * 501);
    cin >> M >> N;
    for(int i = 0; i < M; i++)
        for(int j = 0; j < N; j++)
             cin >> board[i][j];

    dp[0][0] = 1;
    for(int i = 0; i < M; i++)
        for(int j = 0; j < N; j++)
            solution(i, j);
    
    cout << dp[M - 1][N - 1];
}