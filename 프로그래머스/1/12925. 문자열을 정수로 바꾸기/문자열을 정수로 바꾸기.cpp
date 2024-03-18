#include <string>
#include <vector>
using namespace std;

int solution(string s) {
    int answer = 0;
    bool flag = false;
    for(auto c : s)
        if(c == '-') flag = true;
        else if(c == '+') continue;
        else answer = answer * 10 + c - '0';
    if(flag) answer *= -1;
    return answer;
}