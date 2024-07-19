#include <iostream>
#include <queue>
#include <vector>
#define INF 987654321
using namespace std;

struct comp {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
};

vector<vector<pair<int, int>>> edges;
int n, m, from, to, cost, home, target;

int dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
    vector<int> dists(n + 1, INF);
    vector<bool> visited(n + 1, false);
    dists[home] = 0;
    pq.push({home, 0});
    
    while(!pq.empty()) {
        int cur = pq.top().first;
        pq.pop();
        if (visited[cur] || dists[cur] == INF) continue;
        visited[cur] = true;
        
        for (auto ed : edges[cur]) {
            if (dists[cur] + ed.second < dists[ed.first]) {
                dists[ed.first] = dists[cur] + ed.second;
                pq.push({ed.first, dists[ed.first]});
            }
        }
    }
    return dists[target];
}

int main() {
    cin >> n >> m;
    edges.resize(n + 1, vector<pair<int, int>>());
    for (int i = 0; i < m; ++i) {
        cin >> from >> to >> cost;
        edges[from].push_back({to, cost});
    }
    cin >> home >> target;
    cout << dijkstra();
}
