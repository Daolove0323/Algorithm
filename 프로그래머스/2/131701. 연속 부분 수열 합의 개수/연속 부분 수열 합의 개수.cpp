#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> elements) {
    vector<int> v;
    for(int i = 1; i <= elements.size(); ++i) {
        for(int j = 0, sum = 0; j < elements.size(); ++j) {
            for(int k = 0; k < i; ++k) {
                int idx = (j + k) % elements.size();
                sum += elements[idx];
            }
            v.push_back(sum);
            sum = 0;
        }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    return v.size();
}