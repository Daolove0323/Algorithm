#include <iostream>
#include <vector>
#include <queue>
#define MAX 987654321
using namespace std;

int n, e, a, b, c, v1, v2, answer = MAX;
int dist_1_v1, dist_1_v2, dist_v1_v2, dist_v1_n, dist_v2_n;
int edge[801][801];

void init() {
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= n; ++j)
            edge[i][j] = MAX;
    for (int i = 1; i <= n; ++i)
        edge[i][i] = 0;
}

int dijkstra(int from, int to) {
    priority_queue<int> pq;
    vector<int> dists(n + 1, MAX);
    vector<bool> visited(n + 1, false);
    dists[from] = 0;
    pq.push(from);
    while(!pq.empty()) {
        int idx = pq.top();
        pq.pop();
        if (visited[idx] || dists[idx] == MAX) continue;
        visited[from] = true;
        
        for (int i = 1; i <= n; ++i) {
            if (edge[idx][i] != MAX && dists[idx] + edge[idx][i] < dists[i]) {
                dists[i] = dists[idx] + edge[idx][i];
                pq.push(i);
            }
        }
        
    }
    return dists[to];
}

int main() {
    cin >> n >> e;
    init();
    for (int i = 0; i < e; ++i) {
        cin >> a >> b >> c;
        edge[a][b] = edge[b][a] = c;
    }
    cin >> v1 >> v2;
    
    dist_1_v1 = dijkstra(1, v1);
    dist_1_v2 = dijkstra(1, v2);
    dist_v1_v2 = dijkstra(v1, v2);
    dist_v1_n = dijkstra(v1, n);
    dist_v2_n = dijkstra(v2, n);
    
    if (dist_1_v1 != MAX && dist_v1_v2 != MAX && dist_v2_n != MAX)
        answer = min(answer, dist_1_v1 + dist_v1_v2 + dist_v2_n);
    if (dist_1_v2 != MAX && dist_v1_v2 != MAX && dist_v1_n != MAX)
        answer = min(answer, dist_1_v2 + dist_v1_v2 + dist_v1_n);
    if (answer >= MAX) cout << -1;
    else cout << answer;
}
