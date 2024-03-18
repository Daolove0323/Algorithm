#include <iostream>
#include <algorithm>
using namespace std;

int N, M, result = 2500;
char board[50][50];

int main(void) {
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> board[i][j];

    for(int i = 0; i <= N - 8; i++) {
        for(int j = 0; j <= M - 8; j++) {
            int cnt = 0;
            bool check = false;
            
            for(int y = i; y < i + 8; y++) {
                check = !check;
                for(int x = j; x < j + 8; x++) {
                    if(check == true && board[y][x] != board[i][j])
                        cnt++;
                    else if(check == false && board[y][x] == board[i][j])
                        cnt++;
                    check = !check;
                }
            }
            result = min({cnt, 64 - cnt, result});
        }
    }

    cout << result;
}