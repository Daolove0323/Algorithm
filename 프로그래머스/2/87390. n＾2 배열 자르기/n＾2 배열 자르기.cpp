#include <string>
#include <vector>
using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    for(; left <= right; ++left) {
        int row = left / n + 1;
        int col = left % n + 1;
        answer.push_back(max(col, row));
    }
    return answer;
}