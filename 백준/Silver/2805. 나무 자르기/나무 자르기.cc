#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, buf, height, answer;
long long sum;
vector<int> heights;

int bs(int start, int end, int h) {
    if (end - start <= 1) {
        if(heights[start] >= h) return start;
        else return end;
    }
    int mid = (start + end) / 2;
    if (heights[mid] == h) return mid;
    else if (heights[mid] > h) return bs(start, mid, h);
    else return bs(mid + 1, end, h);
}

long long cal(int height) {
    long long sum = 0;
    int idx = bs(0, N - 1, height);
    for (; idx < N; ++idx)
        if (heights[idx] > height)
            sum = sum + (heights[idx] - height);
    return sum;
}

int solution(int start, int end) {
    if (end - start <= 1) {
        if(cal(end) >= M) return end;
        else return start;
    }
    int mid = (start + end) / 2;
    if (cal(mid) == M) return mid;
    else if (cal(mid) < M) return solution(start, mid - 1);
    else return solution(mid, end);
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> buf;
        heights.push_back(buf);
    }
    sort(heights.begin(), heights.end());
    cout << solution(0, heights[N - 1]);
}