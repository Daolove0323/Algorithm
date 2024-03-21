#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0, xCnt = 0, yCnt = 0;
    char x;
    for(auto c : s) {
        if(xCnt == yCnt) {
            ++answer;
            x = c;
            xCnt = yCnt = 0;
        }
        if(c == x) ++xCnt;
        else ++yCnt;
    }
    return answer;
}