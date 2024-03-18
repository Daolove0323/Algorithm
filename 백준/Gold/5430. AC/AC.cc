#include <iostream>
#include <deque>
#include <string>
#include <sstream>
using namespace std;

int T, n, cnt, input;
string s, buf, order;
bool reverse = false;


int main(void) {
    cin >> T;
    while(T--) {
        cin >> order >> n >> s;
        s = s.substr(1, s.size() - 2);
        istringstream iss(s); deque<int> dq; reverse = false; cnt = 0;
        while(getline(iss, buf, ',')) {
            stringstream ssInt(buf);
	        ssInt >> input;
            dq.push_back(input);
        }

        for(auto o : order) {
            if(o == 'R') {
                reverse = !reverse;
            }
            else if(o == 'D') {
                if(++cnt > n) break;
                if(reverse) dq.pop_back();
                else dq.pop_front();
            }
        }
        
        if(cnt > n) {
            cout << "error" << endl;
            continue;
        }
        
        cout << '[';
        if(reverse) {
            for(int i = dq.size() - 1; i >= 0; i--)
                if(i != 0) cout << dq[i] << ',';
                else cout << dq[i];
        }
        else {
            for(int i = 0; i < dq.size(); i++)
                if(i != dq.size() - 1) cout << dq[i] << ',';
                else cout << dq[i];
        
            }
        cout << ']' << endl;
    }
}