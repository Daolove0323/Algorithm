#include <iostream>
#include <queue>
using namespace std;

int N, input;
priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;

int main(void) {
    cin >> N;
    while(N--) {
        cin >> input;
        if(input > 0) minHeap.push(input);
        else if(input < 0) maxHeap.push(input);
        else if(input == 0) {
            if(maxHeap.empty()) {
                if(minHeap.empty())
                    cout << 0 << endl;
                else {
                    cout << minHeap.top() << endl;
                    minHeap.pop();
                }
            }
            else {
                if(minHeap.empty()) {
                    cout << maxHeap.top() << endl;
                    maxHeap.pop();
                }
                else {
                    if(-maxHeap.top() > minHeap.top()) {
                        cout << minHeap.top() << endl;
                        minHeap.pop();
                    }
                    else {
                        cout << maxHeap.top() << endl;
                        maxHeap.pop();
                    }
                }
            }
        }
    }
}