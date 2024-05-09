#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;

int N, M;
string s;
unordered_map<string, int> toInt;
map<int, string> toString;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        cin >> s;
        toInt[s] = i;
        toString[i] = s;
    }
    for (int i = 1; i <= M; ++i) {
        cin >> s;
        if (isdigit(s[0])) cout << toString[stoi(s)] << '\n';
        else cout << toInt[s] << '\n';
    }
}
