#include <iostream>
#include <string>
#include <vector>
using namespace std;

int t, k, min_len, max_len;
string s;

int main() {
    cin >> t;
    while(t--) {
        vector<vector<int>> v('z'-'a'+1);
        min_len = 1e9; max_len = 0;
        cin >> s >> k;
        
        for (int i = 0; i < s.size(); ++i)
            v[s[i] - 'a'].push_back(i);
        
        for (int i = 0; i < 'z'-'a'+1; ++i) {
            for (int j = 0; j < (int)v[i].size() - k + 1; ++j) {
                min_len = min(min_len, v[i][j + k - 1] - v[i][j] + 1);
                max_len = max(max_len, v[i][j + k - 1] - v[i][j] + 1);
            }
        }
        if (min_len == 1e9) cout << -1 << endl;
        else cout << min_len << " " << max_len << endl;
    }
}