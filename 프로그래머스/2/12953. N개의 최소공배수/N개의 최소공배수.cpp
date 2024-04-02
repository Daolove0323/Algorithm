#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
    int r = a % b;
    if(r == 0) return b;
    else return gcd(b, r);
}

int solution(vector<int> arr) {
    vector<int> v = arr;
    sort(v.begin(), v.end(), greater<int>());
    int n = arr[0] * arr[1] / gcd(arr[0], arr[1]);
    for(int i = 2; i < arr.size(); ++i)
        n = n * arr[i] / gcd(n, arr[i]);
    return n;
}