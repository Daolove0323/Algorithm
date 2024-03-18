#include <string>
#include <vector>
using namespace std;

int arr[10];

long long solution(long long n) {
    long long answer = 0;
    while(n > 0) {
        ++arr[n % 10];
        n /= 10;
    }
    
    int i = 9;
    while(i >= 0 || arr[i] > 0) {
        if(arr[i] != 0) {
            answer = answer * 10 + i;
            --arr[i];
        }
        else {
            --i;
        }
    }
    return answer;
}