#include <iostream>
using namespace std;

int N, M, n1, n2, tmp, result;
int parent[1000001];

int findRoot(int n) {
    if (parent[n] == n) return n;
    else return parent[n] = findRoot(parent[n]);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int i = 0; i < 1000001; ++i) parent[i] = i;
    cin >> N >> M;
    for (int i = 1; i <= M; ++i) {
        cin >> n1 >> n2;
        int root1 = findRoot(n1), root2 = findRoot(n2);
        if (root1 == root2) {result = i; break;}
        if (root1 < root2) parent[root2] = root1;
        else parent[root1] = root2;
    }
    cout << result;
}
