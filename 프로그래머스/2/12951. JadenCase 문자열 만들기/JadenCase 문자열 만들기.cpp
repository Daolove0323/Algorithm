#include <string>
#include <vector>
using namespace std;

string solution(string s) {
    bool upper = true;
    for(char& c : s) {
        if(c == ' ') { upper = true; continue; }
        if(upper) { c = toupper(c); upper = false; }
        else { c = tolower(c); }
    }
    return s;
}