#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int success = 0;
string s, t;

void dfs(string str) {
    if (str.size() == t.size()) {
        if (str == t) success = 1;
        return;
    }
    string rev = str;
    reverse(rev.begin(), rev.end());
    if (t.find(str) == string::npos && t.find(rev) == string::npos) return;
    dfs(str + 'A');
    dfs('B' + rev);
}

int main() {
    cin >> s >> t;
    for (int i = 0; i < t.size() - s.size(); ++i) {
        dfs(s);
    }
    cout << success;
}
