#include <iostream>
#include <vector>
using namespace std;

int n, answer;

bool isValid(int r, int c, vector<int>& q) {
    for (int i = 0; i < q.size(); ++i) {
        if (c == q[i]) return false;
        if (abs(r - i) == abs(c - q[i])) return false;
    }
    return true;
}

void dfs(int r, vector<int> q_col) {
    for (int c = 0; c < n; ++c) {
        if (isValid(r, c, q_col)) {
            if (r == n - 1) ++answer;
            else {auto v(q_col); v.push_back(c); dfs(r + 1, v);}
        }
    }
}
int main() {
    cin >> n;
    vector<int> q_col;
    dfs(0, q_col);
    cout << answer;
}
