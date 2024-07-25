#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;
int n, m, op, n1, n2, tmp;

int find_root(int n) {
    if (parent[n] == n) return n;
    return parent[n] = find_root(parent[n]);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    parent.resize(n + 1);
    for (int i = 0; i < parent.size(); ++i) parent[i] = i;
    for (int i = 0; i < m; ++i) {
        cin >> op >> n1 >> n2;
        if (op == 0) {
            if (find_root(n1) != find_root(n2)) {
                parent[find_root(n2)] = find_root(n1);
            }
        } else {
            if (find_root(n1) == find_root(n2)) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
    }
}
