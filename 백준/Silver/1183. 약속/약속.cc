#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, a, b, t, tCount;
vector<int> diff;

int main() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> a >> b;
		diff.push_back(a - b);
	}

	sort(diff.begin(), diff.end());
	if (N % 2 == 1) cout << 1 << '\n';
	else cout << diff[N / 2] - diff[N / 2 - 1] + 1 << '\n';
}