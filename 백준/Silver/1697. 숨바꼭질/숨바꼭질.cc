#include <iostream>
#include <queue>
#include <utility>
using namespace std;

queue<pair<int, int>> q;
bool checked[100001];
int n, k;

int main() {
    cin >> n >> k;
    q.push({n, 0});
    checked[n] = true;
    while(q.front().first != k) {
        int f = q.front().first, s = q.front().second;
        checked[f] = true;
        if (0 <= f + 1 && f + 1 <= 100001 && !checked[f + 1]) q.push({f + 1, s + 1});
        if (0 <= f - 1 && f - 1 <= 100001 && !checked[f - 1]) q.push({f - 1, s + 1});
        if (0 <= f * 2 && f * 2 <= 100001 && !checked[f * 2]) q.push({f * 2, s + 1});
        q.pop();
    }
    cout << q.front().second;
}