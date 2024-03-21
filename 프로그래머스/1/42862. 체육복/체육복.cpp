#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.begin());
    int idx = 0, answer = n - lost.size();
    for(int i = 0; i < lost.size(); ++i) {
        for(int j = idx; j < reserve.size(); ++j) {
            if(lost[i] - 1 == reserve[j] || lost[i] + 1 == reserve[j]) { ++answer; ++idx; break; }
            else if(lost[i] < reserve[j]) { break; }
            else if(lost[i] > reserve[j]) { ++idx; continue;}
        }
    }
    return answer;
}