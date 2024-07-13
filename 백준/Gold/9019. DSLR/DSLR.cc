#include <iostream>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

int t, a, b;
queue<pair<int, string>> q;
bool visited[10000];

int d(int n) {return (n * 2) % 10000;}
int s(int n) {return n == 0 ? 9999 : n - 1;}
int l(int n) {
    int rear = n / 1000;
    return ((n * 10) +rear) % 10000;
}
int r(int n) {
    int back = n % 10;
    return (n / 10) + back * 1000;
}
void process(int n, string s, char c) {
    visited[n] = true;
    q.push({n, s + c});
}

int main() {
    cin >> t;
    while (t--) {
        cin >> a >> b;
        q.push({a, ""});
        while(true) {
            int n = q.front().first;
            string str = q.front().second;
            if (n == b){
                cout << str << '\n';
                break;
            }
            q.pop();
            if (!visited[d(n)]) process(d(n), str, 'D');
            if (!visited[s(n)]) process(s(n), str, 'S');
            if (!visited[l(n)]) process(l(n), str, 'L');
            if (!visited[r(n)]) process(r(n), str, 'R');
        }
        memset(visited, false, 10000);
        while(!q.empty()) q.pop();
    }
}