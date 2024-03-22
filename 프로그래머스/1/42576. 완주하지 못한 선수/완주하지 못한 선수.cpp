#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> um;
    for(string name : completion) ++um[name];
    for(string name : participant) if(--um[name] < 0) return name;
}