#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int cnt = 0;
    sort(citations.begin(), citations.end(), greater<int>());
    for(int i = (citations.size()-1)/2; i < citations.size(); ++i)
        if(i + 1 <= citations[i]) cnt = i + 1;
    return cnt;
}
