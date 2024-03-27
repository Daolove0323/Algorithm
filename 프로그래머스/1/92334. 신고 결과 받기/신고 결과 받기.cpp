#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    unordered_map<string, int> id;
    unordered_map<int, vector<int>> list;
    for(int i = 0; i < id_list.size(); ++i) id[id_list[i]] = i;
    sort(report.begin(), report.end());
    report.erase(unique(report.begin(), report.end()), report.end());
    for(string s : report) {
        int len = 0;
        while(s[len] != ' ') ++len;
        list[id[s.substr(len + 1)]].push_back(id[s.substr(0, len)]);
    }
    for(string s : id_list)
        if(list[id[s]].size() >= k)
            for(auto i : list[id[s]]) ++answer[i];
    return answer;
}