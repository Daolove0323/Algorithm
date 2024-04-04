#include <string>
#include <vector>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <iostream>
using namespace std;

int arr[100001];
vector<pair<int, int>> v;
vector<int> answer;
bool comp(pair<int, int> p1, pair<int, int> p2) {
    return p1.second > p2.second;
}

vector<int> solution(string s) {
    for(auto& c : s) if(!isdigit(c)) c = ' ';
    istringstream iss(s); int n;
    while(iss >> n) ++arr[n];
    for(int i = 0; i < 100001; ++i)
        if(arr[i] != 0) v.push_back({i, arr[i]});
    sort(v.begin(), v.end(), comp);
    for(auto p : v) answer.push_back(p.first);
    return answer;
}