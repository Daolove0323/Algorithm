#include <iostream>
#include <vector>
using namespace std;

int N, buf;

int main() {
    cin >> N;
    vector<int> top(N + 1), answer(N + 1);
    vector<pair<int, int>> stack;
    for(int i = 1; i <= N; ++i) cin >> top[i];
    for(int i  = N; i > 0; --i) {
        while(!stack.empty()) {
            if(stack.back().second <= top[i]) { answer[stack.back().first] = i; stack.pop_back(); }
            else break;
        }
        stack.push_back({i, top[i]});
    }
    for(int i = 1; i <= N; ++i) cout << answer[i] << " ";
}
