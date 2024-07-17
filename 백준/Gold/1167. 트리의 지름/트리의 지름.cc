#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int v, from, to, dist, node_buf, sum_buf;
vector<vector<pair<int, int>>> edge;
bool visited[100001];

void dfs(int idx, int sum) {
    bool isLeaf = true;
    for (auto i : edge[idx]) {
        if (visited[i.first]) continue;
        visited[i.first] = true;
        dfs(i.first, sum + i.second);
        isLeaf = false;
    }
    if (isLeaf && sum_buf < sum) {
        sum_buf = sum;
        node_buf = idx;
    }
}

int main() {
    cin >> v;
    for (int i = 0; i < v + 1; ++i) edge.push_back({});
    for (int i = 0; i < v; ++i) {
        cin >> from;
        while (true) {
            cin >> to;
            if (to == -1) break;
            cin >> dist;
            edge[from].push_back({to, dist});
        }
    }
    visited[1] = true;
    dfs(1, 0);
    sum_buf = 0;
    memset(visited, false, 100001);
    visited[node_buf] = true;
    dfs(node_buf, 0);
        cout << sum_buf;
}