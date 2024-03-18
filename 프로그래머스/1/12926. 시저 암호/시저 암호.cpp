#include <string>
#include <vector>
using namespace std;

string solution(string s, int n) {
    for(auto& c : s) {
        if(c == ' ') continue;
        int i = c + n;
        if(('A' <= c && c <= 'Z' && 'Z' < i) ||
           ('a' <= c && c <= 'z' && 'z' < i))
            i -= 'Z' - 'A' + 1;
        c = i;
    }
        return s;
}