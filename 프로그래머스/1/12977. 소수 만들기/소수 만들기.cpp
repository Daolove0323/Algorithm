#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> nums) {
    vector<bool> isPrime(3001);
    for(int i = 0; i < 3001; ++i) isPrime[i] = true;

    int answer = 0;
    for(int i = 2; i <= 3000; ++i)
        if(isPrime[i])
            for(int j = 2; i * j <= 3000; ++j)
                isPrime[i * j] = false;
    

    for(int i = 0; i < nums.size(); ++i)
        for(int j = i + 1; j < nums.size(); ++j)
            for(int k = j + 1; k < nums.size(); ++k) {
                if(isPrime[nums[i] + nums[j] + nums[k]]) ++answer;
            }
    return answer;
}