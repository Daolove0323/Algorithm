#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<bool> isPrime(1000001);
    for(int i = 0; i < 1000001; ++i) isPrime[i] = true;

    for(int i = 2; i <= 1000001; ++i)
        if(isPrime[i])
            for(int j = 2; i * j <= 1000001; ++j)
                isPrime[i * j] = false;
    for(int i = 2; i <= n; ++i)
        if(isPrime[i]) ++answer;
    return answer;
}