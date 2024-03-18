#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    for(int i = 0, n = -1; i < arr.size(); ++i) {
        if(arr[i] == n) continue;
        answer.push_back(arr[i]);
        n = arr[i];
    }
    return answer;
}