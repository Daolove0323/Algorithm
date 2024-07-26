#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct cmp {
    bool operator()(pair<int, int> p1, pair<int, int> p2) {
        return p1.second > p2.second;
    }
};

int n, m, from, to, cost;
vector<bool> visited;
vector<int> dists;
vector<vector<pair<int, int>>> edges;

void dijkstra() {
    priority_queue<pair<int ,int>, vector<pair<int, int>>, cmp> q;    // 노드 : 비용
    dists[1] = 0; q.push({1, 0});
    
    while (!q.empty()) {
        int nd = q.top().first;
        q.pop();
        if (visited[nd] || dists[nd] == 1e9) continue;
        visited[nd] = true;
        for (int i = 0; i < edges[nd].size(); ++i) {
            int node = edges[nd][i].first;
            int dist = edges[nd][i].second;
            if (visited[node]) continue;
            if (dists[node] <= dists[nd] + dist) continue;
            dists[node] = dists[nd] + dist;
            q.push({node, dists[node]});
        }
    }
}

int main() {
    cin >> n >> m;
    edges.resize(n + 1, vector<pair<int, int>>());
    visited.resize(n + 1, false);
    dists.resize(n + 1, 1e9);
    
    for (int i = 0; i < m; ++i) {
        cin >> from >> to >> cost;
        edges[from].push_back({to, cost});
        edges[to].push_back({from, cost});
    }
    dijkstra();
    cout << dists[n];
}
