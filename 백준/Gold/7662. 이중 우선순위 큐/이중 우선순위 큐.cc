#include <iostream>
#include <queue>
#include <map>
using namespace std;

int t, q, n;
char op;

priority_queue<int, vector<int>, greater<int>> minHeap;
priority_queue<int, vector<int>, less<int>> maxHeap;
map<int, int> m;

void eraseMaxHeap() {
    while (true) {
        if (maxHeap.empty()) return;
        if (m[maxHeap.top()] > 0) return;
        maxHeap.pop();
    }
}
void eraseMinHeap() {
    while (true) {
        if (minHeap.empty()) return;
        if (m[minHeap.top()] > 0) return;
        minHeap.pop();
    }
}

void operate() {
    if (op == 'I') {
        minHeap.push(n);
        maxHeap.push(n);
        ++m[n];
    } else if (n == 1) {
        eraseMaxHeap();
        if (!maxHeap.empty()) {
            --m[maxHeap.top()];
            maxHeap.pop();
        }
    } else {
        eraseMinHeap();
        if (!minHeap.empty()) {
            --m[minHeap.top()];
            minHeap.pop();
        }
    }
}

void printResult() {
    if (maxHeap.empty()) {
        cout << "EMPTY" << '\n';
    } else {
        cout << maxHeap.top() << " " << minHeap.top() << '\n';
    }
}

int main() {
    cin >> t;
    while(t--) {
        cin >> q;
        for (int i = 0; i < q; ++i) {
            cin >> op;
            cin >> n;
            operate();
        }
        eraseMaxHeap();
        eraseMinHeap();
        printResult();
        while(!maxHeap.empty()) maxHeap.pop();
        while(!minHeap.empty()) minHeap.pop();
        m.clear();
    }
}
