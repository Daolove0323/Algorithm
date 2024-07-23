#include <iostream>
#define INF 1e9
using namespace std;

int n, m, f, t, c;
int dists[101][101];

int main() {
    fill_n(dists[0], 101 * 101, INF);
    for (int i = 0; i < 101; ++i) dists[i][i] = 0;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> f >> t >> c;
        dists[f][t] = min(dists[f][t], c);
    }
    
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                dists[i][j] = min(dists[i][j], dists[i][k] + dists[k][j]);
    
    for (int i = 1; i <= n; ++i, cout << endl)
        for (int j = 1; j <= n; ++j)
            if (dists[i][j] == INF) cout << 0 << " ";
            else cout << dists[i][j] << " ";
}
