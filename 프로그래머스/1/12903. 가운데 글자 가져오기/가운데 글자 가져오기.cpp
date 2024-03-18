#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    int len = s.size();
    return len % 2 == 1 ? s.substr(len / 2, 1) : s.substr(len / 2 - 1, 2); 
}