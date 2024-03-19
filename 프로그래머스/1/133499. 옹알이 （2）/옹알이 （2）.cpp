#include <string>
#include <vector>
using namespace std;

string s[] = {"aya", "ye", "woo", "ma"};

int solution(vector<string> babbling) {
    int answer = 0;
    for(string b : babbling) {
        int idx = 0, before = -1;
        for(int i = 0; i < 4; ++i) {
            if(i == before) continue;
            if(b.substr(idx, s[i].size()) == s[i]) {
                idx += s[i].size();
                before = i;
                i = -1;
            }
        }
        if(idx == b.size()) ++answer;
    }
    return answer;
}