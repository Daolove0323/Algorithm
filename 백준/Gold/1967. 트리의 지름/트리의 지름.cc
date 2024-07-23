#include <iostream>
#include <vector>
using namespace std;

int n, f, t, w, far_node, far_distance;
vector<vector<pair<int, int>>> edges;

void dfs(int cur, int from, int dist) {
    for (int i = 0; i < edges[cur].size(); ++i) {
        if (edges[cur][i].first == from) continue;
        dfs(edges[cur][i].first, cur, dist + edges[cur][i].second);
    }
    if (edges[cur].size() == 1 && dist > far_distance) {
        far_distance = dist;
        far_node = cur;
    }
}

int main() {
    cin >> n;
    edges.resize(n + 1, vector<pair<int, int>>());
    for (int i = 0; i < n - 1; ++i) {
        cin >> f >> t >> w;
        edges[f].push_back({t, w});
        edges[t].push_back({f, w});
    }
    dfs(1, 0, 0);
    dfs(far_node, 0, 0);
    cout << far_distance;
}
