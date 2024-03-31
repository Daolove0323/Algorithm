#include <string>
#include <vector>
#include <iostream>
using namespace std;

int oneCount(int n) {
    int cnt = 0;
    for(; n > 0; n /= 2) {
        if(n % 2 == 1) ++cnt;
    }
    return cnt;
}

int solution(int n) {
    int answer = n + 1;
    for(; oneCount(answer) != oneCount(n); ++answer) continue;
    return answer;
}