#include <iostream>

using namespace std;

int solution(int n, int a, int b) {
    for(int i = 0;;++i) {
        if(a == b) return i;
        a = (a + 1) / 2;
        b = (b + 1) / 2;
    }
}