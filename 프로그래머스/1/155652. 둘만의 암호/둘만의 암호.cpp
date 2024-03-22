#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    vector<char> v;
    unordered_map<char, int> um;
    sort(skip.begin(), skip.end());
    for(char c = 'a', idx = 0; c <= 'z'; ++c)
        if(idx >= skip.size() || c != skip[idx]) { um[c] = v.size(); v.push_back(c); }
        else ++idx;
    for(char c : s) answer += v[(um[c] + index) % v.size()];
    return answer;
}