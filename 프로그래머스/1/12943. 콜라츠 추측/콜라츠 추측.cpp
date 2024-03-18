#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    long long n = num;
    while(answer < 500) {
        if(n == 1) return answer;
        if(n % 2 == 0) n /= 2;
        else n = n * 3 + 1;
        ++ answer;
    }
    return -1;
}