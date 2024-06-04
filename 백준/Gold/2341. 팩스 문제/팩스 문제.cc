#include <iostream>
#include <string>
#include <utility>
using namespace std;

int level[4] = {1, 86, 172, 256};
string code[4] = {"00", "01", "10", "11"};

int N, W, buf, n[50];
pair<int, string> dp[4][50];

int main() {
    cin >> N >> W;
    for (int i = 0; i < N; ++i) cin >> n[i];
    
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < N; ++j)
            dp[i][j].first = 987654321;

    for (int i = 0; i < 4; ++i) {
        dp[i][0].first = abs(n[0] - level[i]) + W * 2;
        dp[i][0].second = code[i];
    }
    
    for (int idx = 1; idx < N; ++idx) {
        for (int lv = 0; lv < 4; ++lv) {
            for (int bf = 0; bf < 4; ++bf) {
                auto before = dp[bf][idx - 1];
                int cur = dp[lv][idx].first;
                int dif = abs(n[idx] - level[lv]);
                if (lv == bf) {
                    if (before.first + dif + W < cur)
                        dp[lv][idx] = { before.first + dif + W, before.second + '0' };
                } else {
                    if (before.first + dif + W * 3 < cur)
                        dp[lv][idx] = { before.first + dif + W * 3, before.second + '1' + code[lv] };
                }
            }
        }
    }
    
    int ansLv = 0;
    for (int i = 0; i < 4; ++i)
        if (dp[i][N - 1] < dp[ansLv][N - 1]) ansLv = i;
    
    cout << dp[ansLv][N - 1].first << '\n' << dp[ansLv][N - 1].second;
}
