#include <string>
#include <vector>
using namespace std;

string answer = "No";
vector<string> c1, c2, g;

void recursive(int idx1, int idx2, int cur) {
    if(cur == g.size()) answer = "Yes";
    if(g[cur] == c1[idx1]) recursive(idx1 + 1, idx2, cur + 1);
    if(g[cur] == c2[idx2]) recursive(idx1, idx2 + 1, cur + 1);
}

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    c1 = cards1, c2 = cards2, g = goal;
    recursive(0, 0, 0);
    return answer;
}