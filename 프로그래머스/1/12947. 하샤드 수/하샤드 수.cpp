#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    int sum = 0, n = x;
    while(n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return x % sum == 0;
}