#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <sstream>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    unordered_map<string, int> id;
    unordered_map<int, vector<int>> list;
    for(int i = 0; i < id_list.size(); ++i) id[id_list[i]] = i;
    sort(report.begin(), report.end());
    report.erase(unique(report.begin(), report.end()), report.end());
    for(string s : report) {
        string s1, s2;
        istringstream iss(s);
        iss >> s1 >> s2;
        list[id[s2]].push_back(id[s1]);
    }
    for(string s : id_list)
        if(list[id[s]].size() >= k)
            for(auto i : list[id[s]]) ++answer[i];
    return answer;
}