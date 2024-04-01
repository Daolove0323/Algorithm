#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int solution(int k, vector<int> tangerine) {
    map<int, int> m;
    vector<int> v;
    for(auto t : tangerine) ++m[t];
    for(auto t : m) v.push_back(t.second);
    sort(v.begin(), v.end(), greater<int>());
    for(int i = 0, sum = 0; i < v.size(); ++i) {
        sum += v[i];
        if(sum >= k) return i + 1;
    }
}