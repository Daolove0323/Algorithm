#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer(arr1.size());
    for(int i = 0; i < arr1.size(); ++i) {
        int n = arr1[i] | arr2[i];
        for(int j = 0; j < arr1.size(); j++) {
            if(n % 2 == 0) answer[i] = ' ' + answer[i];
            else answer[i] = '#' + answer[i];
            n /= 2;
        }
    }
    return answer;
}