#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

int solution(string str1, string str2) {
    unordered_map<string, pair<int, int>> um;
    int a = 0, b = 0;
    for(auto& c : str1) c = tolower(c);
    for(auto& c : str2) c = tolower(c);
    for(int i = 0; i < str1.size() - 1; ++i)
        if(isalpha(str1[i]) && isalpha(str1[i + 1]))
            ++um[str1.substr(i, 2)].first;
    for(int i = 0; i < str2.size() - 1; ++i)
        if(isalpha(str2[i]) && isalpha(str2[i + 1]))
            ++um[str2.substr(i, 2)].second;
    for(auto i : um) {
        a += min(i.second.first, i.second.second);
        b += max(i.second.first, i.second.second);
    }
    double d = b == 0 ? 65536 : (double)a / b * 65536;
    return d;
}