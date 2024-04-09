#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

bool isPrime(long long n) {
    if(n == 0 || n == 1) return false;
    if(n == 2 || n == 3) return true;
    for(long long i = 2; i * i <= n; ++i)
        if(n % i == 0) return false;
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    string s; long long buff;
    for(; n > 0; n /= k)
        s = to_string(n % k) + s;
    for(auto& c : s) if(c == '0') c = ' ';
    istringstream iss(s);
    while(iss >> buff) if(isPrime(buff)) ++answer;
    return answer;
}