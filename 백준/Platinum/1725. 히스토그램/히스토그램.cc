#include <iostream>
#include <vector>
using namespace std;

int T, N, buf, maxVal;  // T : 테스트 케이스의 수, N :

int main() {
        cin >> N;
        vector<int> heights(N);
        vector<pair<int, int>> stack, bounds(N);
        for (int i = 0; i < N; ++i) cin >> heights[i];
        
        for (int i = 0; i < N; ++i) {
            while(!stack.empty()) {
                if (heights[i] > stack.back().second) { bounds[i].first= stack.back().first + 1; break; }
                else { stack.pop_back(); }
            }
            stack.push_back({i, heights[i]});
        }
        stack.clear();
        for (int i = 0; i < N; ++i) {
            while(!stack.empty()) {
                if (heights[i] < stack.back().second) { bounds[stack.back().first].second = i - 1; stack.pop_back(); }
                else { break; }
            }
            stack.push_back({i, heights[i]});
        }
        while (!stack.empty()) {
            bounds[stack.back().first].second = N - 1;
            stack.pop_back();
        }
        for (int i = 0; i < N; ++i)
            maxVal = max(maxVal, (bounds[i].second - bounds[i].first + 1) * heights[i]);
        cout << maxVal << '\n';
}
