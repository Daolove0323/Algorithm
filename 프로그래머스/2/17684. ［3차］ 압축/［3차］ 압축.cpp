#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    unordered_map<string, int> toIdx;
    unordered_map<int, string> toString;
    int nextIdx = 27;
    for(char i = 'A'; i <= 'Z'; ++i) {
        string s = ""; s += i;
        toIdx[s] = i - 'A' + 1;
        toString[i - 'A' + 1] = s;
    }
    for(int i = 0, j = 1; i < msg.size(); i += j - 1) {
        for(j = 1; i + j <= msg.size(); ++j) {
            if(toIdx[msg.substr(i, j)] == 0) break;
        }
        answer.push_back(toIdx[msg.substr(i, j - 1)]);
        toIdx[msg.substr(i, j)] = nextIdx;
        toString[nextIdx++] = msg.substr(i, j);
        
    }
    return answer;
}