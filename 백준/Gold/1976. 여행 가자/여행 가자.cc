#include <iostream>
using namespace std;

bool linked[201][201], visited[201];
int parent[201], path[1001];
int N, M, root;

int find_root(int n) {
    if (parent[n] == n) return n;
    else return parent[n] = find_root(parent[n]);
}

void update_root(int n) {
    visited[n] = true;
    int root = find_root(n);
    for (int i = 1; i <= N; ++i) {
        if (linked[n][i] && parent[i] == i) {
            parent[i] = root;
            update_root(i);
        }
    }
}

int main() {
    for (int i = 1; i <= 200; ++i)
        parent[i] = i;
    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            cin >> linked[i][j];
    for (int i = 1; i <= M; ++i)
        cin >> path[i];
    
    for (int i = 1; i <= N; ++i)
        if (visited[i]) continue;
        else update_root(i);
    
    root = parent[path[1]];
    for (int i = 2; i <= M; ++i)
        if (parent[path[i]] != root) {
            cout << "NO" << '\n';
            return 0;
        }
    cout << "YES" << '\n';
}
