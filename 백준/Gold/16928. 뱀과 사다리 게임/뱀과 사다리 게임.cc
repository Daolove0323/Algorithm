#include <iostream>
#include <map>
#include <queue>
#define INF 1e9
using namespace std;

int n, m, from, to;
int answer[101];
map<int, int> ladder;
queue<int> q;

int main() {
    fill_n(answer, 101, INF);
    cin >> n >> m;
    for (int i = 0; i < n + m; ++i) {
        cin >> from >> to;
        ladder[from] = to;
    }
    
    q.push(1);
    answer[1] = 0;
    while (!q.empty()) {
        int n = q.front();
        q.pop();
        
        for (int i = 6; i >= 1; --i) {
            int end = n + i;
            if (end > 100 || answer[end] != INF) continue;
            while (ladder[end] != 0) {
                answer[end] = answer[n] + 1;
                end = ladder[end];
            }
            if (answer[end] != INF) continue;
            q.push(end);
            answer[end] = answer[n] + 1;
            if (end == 100) break;
        }
    }
    cout << answer[100];
}
