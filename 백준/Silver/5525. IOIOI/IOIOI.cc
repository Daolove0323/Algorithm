#include <iostream>
#include <string>
using namespace std;

string s;
bool isI;
int answer, cnt, n, m;

int main() {
    cin >> n >> m >> s;
    for (auto c : s) {
        if (c == 'I') {
            if (isI == true) { // II
                if (cnt >= 2 * n + 1) answer += (cnt - (2 * n + 1)) / 2 + 1;
                cnt = 1;
            } else { // OI
                isI = true;
                ++cnt;
            }
        } else {
            if (isI == true) { // IO
                isI = false;
                ++cnt;
            } else { // OO
                --cnt;
                if (cnt >= 2 * n + 1) answer += (cnt - (2 * n + 1)) / 2 + 1;
                cnt = 0;
            }
        }
    }
    if (s.back() == 'I') {
        if (cnt >= 2 * n + 1) answer += (cnt - (2 * n + 1)) / 2 + 1;
    } else {
        --cnt;
        if (cnt >= 2 * n + 1) answer += (cnt - (2 * n + 1)) / 2 + 1;
    }
    cout << answer;
}
