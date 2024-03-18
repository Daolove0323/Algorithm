#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, d, sum;
vector<int> v;
priority_queue<int> pq;

int main(void) {
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        cin >> d;
        v.push_back(d);
    }

    bool flag = true;
    sort(v.begin(), v.end());
    while(v.size() >= M) {
        for(int i = 0; i < M; i++) if(v[i] > 0) flag = false;
        if(flag == false) break;
        pq.push(-v[0]);
        v.erase(v.begin(), v.begin() + M);
    }
    
    if(!v.empty() && v[0] < 0) {
        pq.push(-v[0]);
        for(int i = 0; i < M; i++) {
            if(v.empty() || v[0] > 0) break;
            v.erase(v.begin());
        }
    }
    
    reverse(v.begin(), v.end());
    while(v.size() >= M) {
        pq.push(v[0]);
        v.erase(v.begin(), v.begin() + M);
    }
    if(!v.empty())
        pq.push(v[0]);
    
    sum += pq.top();
    pq.pop();

    while(!pq.empty()) {
        sum += 2 * pq.top();
        pq.pop();
    }

    cout << sum;
}