#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int n, int m) {
    int div, mul;
    for(int i = 1; i <= min(n, m); ++i)
        if(n % i == 0 && m % i == 0) div = i;
    for(int i = 1, j = 1; ; )
        if(n * i > m * j) ++j;
        else if(n * i < m * j) ++i;
        else return {div, n * i};
}