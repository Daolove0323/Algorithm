#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, buf, front, rear, l, r;
long val = 1e10;
vector<int> v;

int main() {
    cin >> n;
    while (n--) {
        cin >> buf;
        v.push_back(buf);
    }
    rear = (int)v.size() - 1;
    while (front < rear) {
        if (abs(v[rear] + v[front]) < val) {
            val = abs(v[rear] + v[front]);
            l = v[front];
            r = v[rear];
        }
        if (abs(v[rear] + v[front]) > abs(v[rear - 1] + v[front])) --rear;
        else ++front;
    }
    cout << l << " " << r;
}
