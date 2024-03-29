#include <vector>
#include <string>
using namespace std;

int solution(string s) {
    vector<char> v;
    for(char c : s) {
        if(v.size() >= 1 && v.back() == c) v.pop_back();
        else v.push_back(c);
    }
    return v.empty() ? 1 : 0;
}