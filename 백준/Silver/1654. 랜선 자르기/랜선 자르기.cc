#include <iostream>
#include <vector>
using namespace std;

long long K, N, longest, result;
int line[10002];

int cnt = 0;

bool solution(long long len) {
    long long sum = 0;
    for(int i = 0; i < K; i++)
        sum += line[i] / len;
    
    if(sum >= N) {
        // result = max(result, len);
        result = len;
        return true;
        }
    else
        return false;
}

void binarySearch(long long begin, long long end) {
    if(begin == end) return;
    long long mid = (begin + end) / 2 + 1;
    if(solution(mid)) binarySearch(mid, end);
    else binarySearch(begin, mid - 1);
}

int main(void) {
    cin >> K >> N;
    for(int i = 0; i < K; i++) {
        cin >> line[i];
        if(line[i] > longest)
            longest = line[i];
    }

    binarySearch(0, longest);
    cout << result;
}