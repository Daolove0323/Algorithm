#include <string>
#include <vector>
using namespace std;

int solution(int n) {
    int sum = 0;
    while(n != 0) {
        sum *= 3;
        sum += n % 3;
        n /= 3;
    }
    return sum;
}