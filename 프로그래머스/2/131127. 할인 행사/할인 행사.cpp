#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    unordered_map<string, int> um;
    for(int i = 0; i < want.size(); ++i)
        um[want[i]] = number[i];
    for(int i = 0; i < discount.size(); ++i) {
        unordered_map<string, int> check;
        bool success = true;
        for(int j = i; j < i + 10; ++j) {
            if(j >= discount.size()) continue;
            ++check[discount[j]];
        }
        for(pair<string, int> p : um) {
            if(check[p.first] != p.second) {
                success = false;
                break;
            }
        }
        if(success) ++answer;
    }
    return answer;
}