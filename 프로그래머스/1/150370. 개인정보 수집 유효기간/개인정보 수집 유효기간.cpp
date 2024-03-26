#include <string>
#include <vector>
#include <iostream>
using namespace std;

struct date {
    int y, m, d;
    bool operator<(const date& D) {
        if(this-> y != D.y) return y < D.y;
        else if(this-> m != D.m) return m < D.m;
        else return d <= D.d;
    }
    void Update() {
        if(m > 12) { y += m / 12; m %= 12; }
        if(m == 0) { y -= 1; m += 12; }
    }
    
};
date returnDate(string s) {
    int y = stoi(s.substr(0, 4));
    int m = stoi(s.substr(5, 2));
    int d = stoi(s.substr(8, 2));
    return {y, m, d};
}
int term['Z' - 'A' + 1];
vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    date now = returnDate(today);
    for(string s : terms) term[s[0] - 'A'] += stoi(s.substr(2));
    for(int i = 0; i < privacies.size(); ++i) {
        date D = returnDate(privacies[i]);
        D.m += term[privacies[i].back() - 'A'];
        D.Update();
        if(D < now) answer.push_back(i + 1);
    }
    return answer;
}