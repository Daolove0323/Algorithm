#include <iostream>
#include <string>
using namespace std;

string s1, s2, answer;
int dp[1002][1002];

int main(void) {
    cin >> s1 >> s2;
    for(int i = 1; i <= s1.size(); i++)
        for(int j = 1; j <= s2.size(); j++)
            if(s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

    int r = s1.size(), c = s2.size();
    while(r != 0 && c != 0) {
        if(s1[r - 1] == s2[c - 1]) {
            answer = s1[r - 1] + answer;
            r--;
            c--;
        }
        else if(dp[r - 1][c] > dp[r][c - 1])
            r--;
        else
            c--;
    }
    if(answer.size() == 0) cout << 0;
    else cout << answer.size() << '\n' << answer;
}