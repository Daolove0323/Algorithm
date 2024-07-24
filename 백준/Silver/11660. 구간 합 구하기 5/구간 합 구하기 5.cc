#include <iostream>
using namespace std;

int n, m, x_1, y_1, x_2, y_2, tmp;
int arr[1025][1025];
int sum[1025][1025];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> arr[i][j];
    sum[1][1] = arr[1][1];
    
    for (int i = 2; i <= n; ++i)
        sum[1][i] = sum[1][i - 1] + arr[1][i];
    for (int i = 2; i <= n; ++i)
        sum[i][1] = sum[i - 1][1] + arr[i][1];
    for (int i = 2; i <= n; ++i)
        for (int j = 2; j <= n; ++j)
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + arr[i][j];
    
    for (int i = 0; i < m; ++i) {
        cin >> y_1 >> x_1 >> y_2 >> x_2;
        if (x_1 > x_2) {tmp = x_1; x_1 = x_2; x_2 = tmp;}
        if (y_1 > y_2) {tmp = y_1; y_1 = y_2; y_2 = tmp;}
        cout << sum[y_2][x_2] - sum[y_2][x_1 - 1] - sum[y_1 - 1][x_2] + sum[y_1 - 1][x_1 - 1] << '\n';
    }
}
