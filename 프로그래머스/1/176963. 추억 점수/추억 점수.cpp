#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    unordered_map<string, int> um;
    for(int i = 0; i < name.size(); ++i)
        um[name[i]] = yearning[i];
    for(auto ph : photo) {
        int sum = 0;
        for(auto one : ph) {
            sum += um[one];
        }
        answer.push_back(sum);
    }            
    return answer;
}