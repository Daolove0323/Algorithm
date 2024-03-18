#include <string>
#include <vector>
using namespace std;

string num[] = {"zero", "one", "two", "three", "four", 
              "five", "six", "seven", "eight", "nine"};

int solution(string s) {
    string answer = "";
    for(int i = 0; i < s.size(); ++i) {
        if('0' <= s[i] && s[i] <= '9') {
            answer += s[i];
            continue;
        }
        for(int j = 0; j < 10; ++j) {
            if(s.substr(i, num[j].size()) == num[j]) {
                answer += j + '0';
                i += num[j].size() - 1;
            }
        }
    }
    return stoi(answer);
}