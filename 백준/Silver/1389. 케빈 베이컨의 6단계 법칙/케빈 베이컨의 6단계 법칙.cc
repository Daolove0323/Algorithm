#include <iostream>
using namespace std;

int N, M, from, to, minSum = 987654321, answer;
int dist[101][101];

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        cin >> from >> to;
        dist[from][to] = dist[to][from] = 1;
    }
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            for (int k = 1; k <= N; ++k) {
                if (j == k || dist[j][i] == 0 || dist[i][k] == 0) continue;
                if (dist[j][k] == 0) dist[j][k] =dist[j][i] + dist[i][k];
                else dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
            }
    for (int i = 1; i <= N; ++i) {
        int sum = 0;
        for (int j = 1; j <= N; ++j) {
            sum += dist[i][j];
        }
        if (sum < minSum) {
            minSum = sum;
            answer = i;
        }
    }
    cout << answer;
}
