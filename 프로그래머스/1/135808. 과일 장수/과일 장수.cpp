#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    sort(score.begin(), score.end());
    for(int i = 1; (int)score.size() - i * m + 1 > 0; ++i)
        answer += score[(int)score.size() - i * m] * m;
    return answer;
}