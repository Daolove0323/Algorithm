#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int T, N, M;

void print(int N, int M) {
    vector<int> v;
    queue<pair<int, int>> q;
    int val, idx = 0, cnt = 1;
    for(int i = 0; i < N; i++) {
        cin >> val;
        v.push_back(val);
        q.push({val, i});
    }
    sort(v.begin(), v.end(), greater<int>());
    
    while(true) {
        if(q.front().first == v[idx]) {
            if(q.front().second == M) {
                cout << cnt << endl;
                break;
            }
            else {
                idx++, cnt++;
                q.pop();
            }
        }
        else {
            q.push(q.front());
            q.pop();
        }
    }
}
int main(void) {
    cin >> T;
    while(T--) {
        cin >> N >> M;
        print(N, M);
    }
}