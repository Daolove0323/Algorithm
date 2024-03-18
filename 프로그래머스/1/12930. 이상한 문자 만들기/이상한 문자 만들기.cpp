#include <string>
#include <vector>
using namespace std;

string solution(string s) {
    bool flag = true;
    for(auto& c : s) {
        if(c == ' ') flag = false;
        else if(flag && 'a' <= c && c <= 'z') c -= 'a' - 'A';
        else if(!flag && 'A' <= c && c <= 'Z') c += 'a' - 'A';
        flag = !flag;
    }
    return s;
}