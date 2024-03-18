#include <iostream>
using namespace std;

long long a, b, c;

long long solution(long i1, long i2) {
    if(i2 == 1) return i1 % c;
    
    if(i2 % 2 == 0) {
        long long tmp = solution(i1, i2 / 2) % c;
        return (tmp * tmp) % c;
    }
    else {
        long long tmp = solution(i1, (i2 - 1) / 2) % c;
        return ((tmp * tmp % c) * i1) % c;
    }
} 

int main(void) {
    cin >> a >> b >> c;
    cout << solution(a, b) % c;
}