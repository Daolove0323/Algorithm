#include <iostream>
using namespace std;

const int white = 0;
const int blue = 1;

int N, whiteCnt, blueCnt;
int paper[128][128];

void recursive(int x, int y, int len) {
    int color = paper[x][y];
    
    for(int i = x; i < x + len; i++)
        for(int j = y; j < y + len; j++)
            if(paper[i][j] != color) {
                recursive(x, y, len / 2);
                recursive(x + len / 2, y, len / 2);
                recursive(x, y + len / 2, len / 2);
                recursive(x + len / 2, y + len / 2, len / 2);
                return;
            }

    if(color == white) whiteCnt++;
    else blueCnt++;
}

int main(void) {
    cin >> N;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> paper[i][j];
    recursive(0, 0, N);
    cout << whiteCnt << '\n' << blueCnt;
}