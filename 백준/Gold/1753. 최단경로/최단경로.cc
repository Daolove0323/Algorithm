#include <iostream>
#include <vector>
#include <queue>
#include <map>
#define INF 987654321
using namespace std;

struct cmp {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
};

int v, e, k, from, to, dist;
vector<vector<pair<int, int>>> edges;
vector<int> dists;
vector<bool> visited;
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

int main() {
    cin >> v >> e >> k;
    edges.resize(v + 1, vector<pair<int, int>>());
    for (int i = 0; i < e; ++i) {
        cin >> from >> to >> dist;
        edges[from].push_back({to, dist});
    }
        
    dists.resize(v + 1, INF);
    visited.resize(v + 1, false);
    dists[k] = 0;
    pq.push({k, 0});
    while(!pq.empty()) {
        int cur = pq.top().first;
        pq.pop();
        if (visited[cur] || dists[cur] == INF) continue;
        visited[cur] = true;
        
        for (auto edge : edges[cur]) {
            if (dists[cur] + edge.second < dists[edge.first]) {
                dists[edge.first] = dists[cur] + edge.second;
                pq.push({edge.first, dists[edge.first]});
            }
        }
    }

    for (int i = 1; i <= v; ++i) {
        if (dists[i] == INF) cout << "INF" << '\n';
        else cout << dists[i] << '\n';
    }
}