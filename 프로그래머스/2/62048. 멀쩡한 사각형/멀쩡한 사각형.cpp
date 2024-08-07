#include <iostream>
#include <vector>
#include <string>
using namespace std;

int gcd(int a, int b) { 
    if (b == 0) return a;
    else return gcd(b, a % b);
}

long long solution(int w,int h) {
    if (w < h) { int tmp = w; w = h; h = tmp; }
    return (long long)w * h - (w + h - gcd(w, h));
}