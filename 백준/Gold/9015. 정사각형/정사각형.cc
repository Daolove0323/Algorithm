#include <iostream>
#include <set>
#include <vector>
using namespace std;

int T, N, x, y;

int main() {
    cin >> T;
    while (T--) {
        cin >> N;
        int areaSquare = 0;
        set<pair<int, int>> s;
        vector<pair<int, int>> v;
        for (int i = 0; i < N; ++i) {
            cin >> y >> x;
            s.insert({y, x});
            v.push_back({y, x});
        }
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                int y1 = v[i].first, x1 = v[i].second;
                int y2 = v[j].first, x2 = v[j].second;
                int y3 = y2 + (x2 - x1), x3 = x2 - (y2 - y1);
                int y4 = y1 + (x2 - x1), x4 = x1 - (y2 - y1);
                if ((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) >= areaSquare &&
                    s.find({y3, x3}) != s.end() && s.find({y4, x4}) != s.end())
                    areaSquare = max(areaSquare, (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
            }
        }
        cout << areaSquare << '\n';
    }
}
