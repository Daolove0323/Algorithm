#include <iostream>
#include <string>
using namespace std;

int T;
string s;

bool isValid(string s) {
    int left = 0, right = 0;
    for(char c : s) {
        if(c == '(') ++left;
        else ++right;
        if(left < right) return false;
    }
    return left == right;
}

int main() {
    cin >> T;
    while(T--) {
        cin >> s;
        if(isValid(s)) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}