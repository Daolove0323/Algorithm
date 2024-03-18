#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int M = 0, m = 0;
    for(auto i : sizes) {
        if(max(i[0], i[1]) > M) M = max(i[0], i[1]);
        if(min(i[0], i[1]) > m) m = min(i[0], i[1]);
    }
    return M * m;
}