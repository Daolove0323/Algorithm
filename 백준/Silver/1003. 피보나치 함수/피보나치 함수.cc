#include <iostream>
#include <utility>
using namespace std;

int T, N;
pair<int, int> fibo[41];

int main() {
    fibo[0] = {1, 0}, fibo[1] = {0, 1};
    for (int i = 2; i <= 40; ++i)
        fibo[i] = {fibo[i - 1].first + fibo[i - 2].first, fibo[i - 1].second + fibo[i - 2].second};
    cin >> T;
    while (T--) {
        cin >> N;
        cout << fibo[N].first << " " << fibo[N].second << '\n';
    }
}