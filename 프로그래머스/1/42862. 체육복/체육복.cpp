#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> students(32, 1);
    for(int l : lost) --students[l];
    for(int r : reserve) ++students[r];
    for(int i = 1; i <= n; ++i)
        if(students[i] == 2) {
            if(students[i - 1] == 0)
                students[i] = students[i - 1] = 1;
            else if(students[i + 1] == 0)
                students[i] = students[i + 1] = 1;
        }
    for(int i = 1; i <= n; ++i) if(students[i] != 0) ++answer;
    return answer;
}