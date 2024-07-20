#include <iostream>
#include <string>
using namespace std;

int n, m;

void comb(int idx, int left, string s) {
    if (left == 0) {
        cout << s << '\n';
        return;
    }
    for (int i = idx; i <= n; ++i) {
        if (left == m) comb(i + 1, left - 1, to_string(i));
        else comb(i + 1, left - 1, s + " " + to_string(i));
    }
}
int main() {
    cin >> n >> m;
    comb(1, m, "");
}