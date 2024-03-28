#include <string>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

string solution(string s) {
    istringstream iss(s);
    int i, m = 2147483647, M = -2147483648;
    while(iss >> i) {m = min(m, i); M = max(M, i);}
    return to_string(m) + " " + to_string(M);
}