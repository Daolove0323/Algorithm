#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, buf;
vector<int> solution;
vector<int> arr;
vector<bool> checked;

bool cmp(vector<int>& v1, vector<int>& v2) {
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    if (v1.size() != v2.size()) return false;
    for (int i = 0; i < v1.size(); ++i)
        if (v1[i] != v2[i]) return false;
    return true;
}

bool unique(vector<int>& v) {
    for (int i = 0; i < v.size() - 1; ++i)
        if (v[i] == v[i + 1]) return false;
    return true;
}

void dfs(int idx, vector<int> v1, vector<int> v2) {
    v1.push_back(idx);
    v2.push_back(arr[idx]);
    if (!unique(v2)) return;
    if (cmp(v1, v2)) {
        for (int i : v1) {
            solution.push_back(i);
            checked[i] = true;
        }
        return;
    }
    dfs(arr[idx], v1, v2);
}

int main() {
    cin >> n;
    arr.resize(n + 1, 0);
    checked.resize(n + 1, false);
    for (int i = 1; i <= n; ++i) {
        cin >> buf;
        arr[i] = buf;
    }
    
    for (int i = 1; i <= n; ++i) {
        if (checked[i]) continue;
        dfs(i, vector<int>(), vector<int>());
    }
    
    sort(solution.begin(), solution.end());
    cout << solution.size() << '\n';
    for (int i : solution) cout << i << '\n';
}
