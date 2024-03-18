#include <iostream>
using namespace std;

int N, r, c;

int powOfTwo(int n) {
    int num = 1;
    for(int i = 0; i < n; i++) num *= 2;
    return num;
}

int recursive(int N, int r, int c) {
    if(N == 1) return r * 2 + c + 1;
    
    int half = powOfTwo(N - 1);
    if(r < half) {
        if(c < half) return recursive(N - 1, r, c);
        else return recursive(N - 1, r, c - half) + half * half;
    }
    else {
        if(c < half) return recursive(N - 1, r - half, c) + 2 * half * half;
        else return recursive(N - 1, r - half, c - half) + 3 * half * half;
    }
}

int main(void) {
    cin >> N >> r >> c;
    cout << recursive(N, r, c) - 1;
}