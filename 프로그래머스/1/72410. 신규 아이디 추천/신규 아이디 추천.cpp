#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string new_id) {
    string answer, temp;
    // 1단계
    for(char c : new_id)
        if('A' <= c && c <= 'Z') answer += c + 'a' - 'A';
        else answer += c;
    // 2단계
    for(char c : answer)
        if(('a' <= c && c <= 'z') || ('0' <= c && c <= '9') ||
           (c == '-' || c == '_' || c == '.'))
           temp += c;
    answer = temp;
    temp = "";
    // 3단계
    bool beforeIsDot = false;
    for(char c : answer)
        if(c == '.' && !beforeIsDot) { temp += c; beforeIsDot = true; }
        else if(c != '.') {temp += c; beforeIsDot = false; }
    answer = temp;
    temp = "";
    // 4단계
    answer = answer[0] == '.' ? answer.substr(1) : answer;
    answer = answer[answer.size() - 1] == '.' ? answer.substr(0, answer.size() - 1) : answer;
    // 5단계
    if(answer.size() == 0) answer = 'a';
    // 6단계
    if(answer.size() >= 16) {
        int i;
        for(i = 14; i >= 0; --i) if(answer[i] != '.') break;
        answer = answer.substr(0, i + 1);
    }
    // 7단계
    for(char c = answer[answer.size() - 1]; answer.size() <=2;)
        answer += c;
    return answer;
}