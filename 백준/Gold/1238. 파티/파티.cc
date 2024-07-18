#include <iostream>
#include <queue>
#define MAX 987654321
using namespace std;

int n, m, x, from, to, dist, answer;
int dists[1001][1001];

void init() {
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            dists[i][j] = MAX;
}

void floyd_warshall() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k <= n; ++k) {
                dists[j][k] = min(dists[j][k], dists[j][i] + dists[i][k]);
            }
        }
    }
}

int main() {
    cin >> n >> m >> x;
    init();
    for (int i = 1; i <= n; ++i)
        dists[i][i] = 0;
    for (int i = 1; i <= m; ++i) {
        cin >> from >> to >> dist;
        dists[from][to] = dist;
    }
    floyd_warshall();
    for (int i = 1; i <= n; ++i)
        answer = max(answer, dists[i][x] + dists[x][i]);
    cout << answer;
}