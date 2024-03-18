#include <iostream>
using namespace std;

int a, b, c;
int dp[21][21][21];

int w(int a, int b, int c){
    int val;
    if(a <= 0 || b <= 0 || c <= 0) return 1;
    else if(a > 20 || b > 20 || c > 20) return dp[20][20][20] ? dp[20][20][20] : dp[20][20][20] = w(20, 20, 20);
    else if(dp[a][b][c]) return dp[a][b][c];
    else if(a < b && b < c) val = w(a, b, c- 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    else val = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
    return dp[a][b][c] = val;
}

int main(void){
    while(true){
        scanf("%d %d %d", &a, &b, &c);
        if(a == -1 && b == -1 && c == -1) break;
        printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
    }
}