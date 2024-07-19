#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;

struct edge {
    int from, to, cost;
};

int tc, n, m, w, s, e, t;
vector<edge> edges;

void bellman_ford() {
    vector<int> dist(n + 1, 0);
    for (int i = 0; i < n - 1; ++i) {
        for (auto ed : edges) {
            dist[ed.to] = min(dist[ed.to], dist[ed.from] + ed.cost);
        }
    }
    for (auto ed : edges) {
        if (dist[ed.from] + ed.cost < dist[ed.to]) {
            cout << "YES" << '\n';
            return;
        }
    }
    cout << "NO" << '\n';
}

int main() {
    cin >> tc;
    while (tc--) {
        cin >> n >> m >> w;
        for (int i = 0; i < m; ++i) {
            cin >> s >> e >> t;
            edges.push_back({s, e, t});
            edges.push_back({e, s, t});
        }
        for (int i = 0; i < w; ++i) {
            cin >> s >> e >> t;
            edges.push_back({s, e, -t});
        }
        bellman_ford();
        edges.clear();
    }
}