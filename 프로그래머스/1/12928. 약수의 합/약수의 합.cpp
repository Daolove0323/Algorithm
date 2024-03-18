#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(int n) {
    int answer = 0;
    for(int i = 1; i < sqrt(n) + 0.1; ++i) {
        if(n % i == 0) {
            if(i == n / i) answer += i;
            else answer += i + n / i;
        }
    }
    return answer;
}