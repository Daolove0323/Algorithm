#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, a, b, used, cnt;
int dp[100001];
vector<pair<int, int>> v;
bool cmp(pair<int, int> p1, pair<int, int> p2) {
    if (p1.second == p2.second) return p1.first < p2.first;
    else return p1.second < p2.second;
}

int main() {
    cin >> n;
    while (n--) { cin >> a >> b; v.push_back({a, b}); }
    sort(v.begin(), v.end(), cmp);
    for (auto p : v)
        if (used <= p.first) { ++cnt; used = p.second; }
    cout << cnt;
}