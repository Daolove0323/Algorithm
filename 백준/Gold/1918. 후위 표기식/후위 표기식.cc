#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

string infix, postfix;
vector<char> op;
map<char, int> m;

int toPostfix(int idx) {
    while (idx < infix.size()) {
        char c = infix[idx];
        if ('A' <= c && c <= 'Z') { // 문자 입력
            postfix += c;
        } else if (c == '(') {  // '(' 입력
            op.push_back(c);
            idx = toPostfix(idx + 1);   // ')' 입력
        } else if (c == ')') {
            break;
        } else if (op.empty() || m[c] > m[op.back()]) {    // 스택에 넣을 수 있는 연산자 입력
            op.push_back(c);
        } else if (m[c] <= m[op.back()]) {     // 스택에 바로 넣을 수 없는 연산자 입력
            if(op.back() != '(') postfix += op.back();
            op.pop_back();
            while (!op.empty() && m[c] <= m[op.back()]) {
                if(op.back() != '(') postfix += op.back();
                op.pop_back();
            }
            op.push_back(c);
        }
        ++idx;
    }
    while (!op.empty()) {
        if (op.back() == '(') {
            op.pop_back();
            break;
        }
        if(op.back() != '(') postfix += op.back();
        op.pop_back();
    }
    return idx;
}

int main() {
    m['('] = -1; m['+'] = 1; m['-'] = 1; m['*'] = 2; m['/'] = 2;
    cin >> infix;
    toPostfix(0);
    cout << postfix;
}
