#include <iostream>
#include <queue>
#include <functional>
#include <vector>
using namespace std;

int N, input;
bool q1_turn = true;
priority_queue<int, vector<int>, less<int>> q1; // 내림차순
priority_queue<int, vector<int>, greater<int>> q2; // 오름차순

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    while(N--) {
        cin >> input; // 입력
        
        if(q1_turn) q1.push(input); // 삽입
        else q2.push(input);
        
        if(!q2.empty() && q1.top() > q2.top()) { // 교환
            int tmp1 = q1.top();
            int tmp2 = q2.top();
            q1.pop();
            q2.pop();
            q2.push(tmp1);
            q1.push(tmp2);
        }
        
    cout << q1.top() << '\n'; // 출력
    q1_turn = !q1_turn; // 턴 교체
    }
}