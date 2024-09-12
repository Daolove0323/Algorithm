#include <string>
#include <vector>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0, chulsu = 0, brother = 0;
    vector<int> v(10001, 0);
    vector<bool> w(10001, false);
    for (auto i : topping)
        if (v[i]++ == 0) ++chulsu;
    for (auto i : topping) {
        if (--v[i] == 0) --chulsu;
        if (w[i] == false) {
            w[i] = true;
            ++brother;
        }
        if (chulsu == brother) ++answer;
    }
    return answer;
}