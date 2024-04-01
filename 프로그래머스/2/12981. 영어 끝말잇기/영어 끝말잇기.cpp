#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    unordered_map<string, bool> um;
    um[words[0]] = true;
    for(int i = 1; i < words.size(); ++i) {
        if(words[i - 1].back() == words[i].front() && um[words[i]] == false)
            um[words[i]] = true;
        else
            return {i % n + 1, i / n + 1};
    }
    return {0, 0};
}