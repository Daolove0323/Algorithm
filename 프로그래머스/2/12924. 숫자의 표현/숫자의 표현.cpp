#include <string>
#include <vector>
using namespace std;

int solution(int n) {
    int answer = 0, start = 1, end = 1;
    while(start <= n) {
        int sum = end * (end + 1) / 2 - (start - 1) * start / 2;
        if(sum  == n) { ++start; ++answer; }
        else if(sum < n) { ++end; }
        else ++start;
    }
    return answer;
}