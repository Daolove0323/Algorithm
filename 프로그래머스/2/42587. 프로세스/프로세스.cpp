#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 1, idx = 0;
    queue<pair<int, int>> q;
    for(int i = 0; i < priorities.size(); ++i)
        q.push({i, priorities[i]});
    sort(priorities.begin(), priorities.end(), greater<int>());
    while(true) {
        if(q.front().second == priorities[idx]) {
            if(q.front().first == location) break;
            q.pop();
            ++idx;
            ++answer;
        } else {
            auto p = q.front();
            q.pop();
            q.push(p);
        }
    }
    return answer;
}