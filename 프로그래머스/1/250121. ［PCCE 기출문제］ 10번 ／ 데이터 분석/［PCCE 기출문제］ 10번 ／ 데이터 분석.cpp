#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> answer;
int ext_idx, sort_idx;
string arr[4] = {"code", "date", "maximum", "remain"};

bool comp(vector<int> v1, vector<int> v2) {
    return v1[sort_idx] < v2[sort_idx];
}
vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    for(int i = 0; i < 4; ++i) {
        if(arr[i] == ext) ext_idx = i;
        if(arr[i] == sort_by) sort_idx = i;
    }
    for(auto d : data)
        if(d[ext_idx] < val_ext) answer.push_back(d);
    sort(answer.begin(), answer.end(), comp);
    return answer;
}