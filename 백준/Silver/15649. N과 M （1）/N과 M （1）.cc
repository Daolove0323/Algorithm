#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

void permutation(vector<int> v, int maximum, int size) {
    if(v.size() == size) {
        for(auto i : v) cout << i << " ";
        cout << '\n';
    }

    for(int i = 1; i <= maximum; i++) {
        auto iter = find(v.begin(), v.end(), i);
        if(iter != v.end()) continue;
        vector<int> v2 = v;
        v2.push_back(i);
        permutation(v2, maximum, size);
    }
}

int main(void) {
    cin >> N >> M;
    vector<int> v;
    permutation(v, N, M);
}