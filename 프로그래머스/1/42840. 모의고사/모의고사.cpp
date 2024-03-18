#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int f[] = {1, 2, 3, 4, 5};
int s[] = {2, 1, 2, 3, 2, 4, 2, 5};
int t[] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int c1 = 0, c2 = 0, c3 = 0, i1 = 0, i2 = 0, i3 = 0;
    for(auto answer : answers) {
        if(f[i1++] == answer) ++c1;
        if(s[i2++] == answer) ++c2;
        if(t[i3++] == answer) ++c3;
        i1 = i1 % (sizeof(f) / sizeof(int));
        i2 = i2 % (sizeof(s) / sizeof(int));
        i3 = i3 % (sizeof(t) / sizeof(int));
    }
    int M = max({c1, c2, c3});
    if(c1 == M) answer.push_back(1);
    if(c2 == M) answer.push_back(2);
    if(c3 == M) answer.push_back(3);
    return answer;
}