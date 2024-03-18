#include <iostream>
#include <vector>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int R, C, result;
char board[20][20];
bool visited[20][20];
bool alpha[26];

void dfs(int row, int col, int cnt){
    result = max(result, cnt);
    visited[row][col] = true;
    alpha[board[row][col] - 'A'] = true;
    
    for(int i = 0; i < 4; i++){
        int ny = row + dy[i];
        int nx = col + dx[i];
        if(R <= ny || ny < 0 || C <= nx || nx < 0 ||
            visited[ny][nx] || alpha[board[ny][nx] - 'A']) continue;
        dfs(ny, nx, cnt + 1);
        }

    visited[row][col] = false;
    alpha[board[row][col] - 'A'] = false;
}

int main(void){
	ios_base::sync_with_stdio(false);
    scanf("%d %d", &R, &C);
	for(int i = 0; i < R; i++)
    	scanf("%s", board[i]);

    dfs(0, 0, 1);
    printf("%d", result);
}