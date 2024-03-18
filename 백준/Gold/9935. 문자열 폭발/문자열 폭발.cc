#include <iostream>
#include <string>
#include <deque>
using namespace std;

string s1, s2;
deque<char> dq;
int cnt;

int main(void) {
    cin >> s1 >> s2;
    for(int i = 0; i < s1.size(); i++) {
        if(s1[i] == s2[cnt]) cnt++;
        else if(s1[i] == s2[0]) cnt = 1;
        else cnt = 0;
        dq.push_back(s1[i]);
        
        if(cnt == s2.size()) {
            for(int i = 0; i < s2.size(); i++) dq.pop_back();
            cnt = 0;
            for(int j = dq.size() > s2.size() ? dq.size() - s2.size() : 0; j < dq.size(); j++) {
                if(dq[j] == s2[cnt]) cnt++;
                else if(dq[j] == s2[0]) cnt = 1;
                else cnt = 0;
            }
        }
    }
    if(dq.empty()) cout << "FRULA";
    else
    for(auto c : dq) {
        cout << c;
    }
}