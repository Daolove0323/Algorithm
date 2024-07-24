#include <iostream>
#include <vector>
#include <map>
using namespace std;

long long n;
map<long long, vector<vector<long long>>> m;

vector<vector<long long>> mul_matrix(vector<vector<long long>>& v1, vector<vector<long long>>& v2) {
    vector<vector<long long>> v3(v1.size(), vector<long long>(v2[0].size()));
    for (int i = 0; i < v1.size(); ++i) {
        for (int j = 0; j < v2[0].size(); ++j) {
            int sum = 0;
            for (int k = 0; k < v2.size(); ++k) {
                sum += (v1[i][k] * v2[k][j] % 1'000'000'007);
            }
            v3[i][j] = sum % 1'000'000'007;
        }
    }
    return v3;
}

int main() {
    cin >> n;
    vector<vector<long long>> v = {{1, 1}, {1, 0}};
    m[0] = v;
    for (long long num = n, i = 1; num > 0; ++i, num/= 2)
        m[i] = mul_matrix(m[i - 1], m[i - 1]);
    
    vector<vector<long long>> w = {{1, 0}, {0, 1}};
    for (long long num = n - 1, i = 0; num > 0; ++i, num/= 2) {
        if (num % 2 == 1) w = mul_matrix(w, m[i]);
    }
    cout << w[0][0];
}
