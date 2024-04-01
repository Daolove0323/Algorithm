#include <iostream>

using namespace std;

int solution(int n, int a, int b) {
    for(int i = 1;;++i) {
        if((a % 2 == 1 && a + 1 == b) || (b % 2 == 1 && b + 1 == a)) return i;
        a = (a + 1) / 2;
        b = (b + 1) / 2;
    }
}