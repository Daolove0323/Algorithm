#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    auto answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(auto i : scoville) pq.push(i);
    while(pq.top() < K) {
        if(pq.size() < 2) return -1;
        int f = pq.top();
        pq.pop();
        int s = pq.top();
        pq.pop();
        pq.push(f + 2 * s);
        ++answer;
    }
    return answer;
}