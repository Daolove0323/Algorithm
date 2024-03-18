#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int N, cnt;

int main(void) {
    cin >> N;
    stack<vector<int>> s;
    for(int i = 0; i < N; i++) s.push({i});
    
    while(!s.empty()) {
        vector<int> v = s.top();
        s.pop();
        
        if(v.size() == N) {
            cnt++;
            continue;
        }

        for(int i = 0; i < N; i++) {
            // 대각선, 직선
            bool pass = true;
            for(int j = 0; j < v.size(); j++)
                if(v[j] - i == v.size() - j || v[j] - i == j - v.size() || v[j] == i) {
                    pass = false;
                    break;
                }
            if(pass == false) continue;
            
            // 8칸
            if(-1 <= v.back() - i && v.back() - i <= 1) continue;
            vector<int> v2 = v;
            v2.push_back(i);
            s.push(v2);
        }
    }      
    cout << cnt;
}