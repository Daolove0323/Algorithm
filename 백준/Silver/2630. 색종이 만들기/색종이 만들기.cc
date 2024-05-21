#include <iostream>
using namespace std;

#define WHITE 0
#define BLUE 1

int n, white, blue;
int arr[128][128];

void check(int y, int x, int l) {
    int color = arr[y][x];
    for (int i = 0; i < l; ++i)
        for (int j = 0; j < l; ++j)
            if (arr[y + i][x + j] != color) {
                check(y, x, l/2);
                check(y+l/2, x, l/2);
                check(y, x+l/2, l/2);
                check(y+l/2, x+l/2, l/2);
                return;
            }
    if(color == WHITE) ++white;
    else ++blue;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> arr[i][j];
    check(0, 0, n);
    cout << white << " " << blue;
}