#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, M, result = 999999999;
int map[51][51];
vector<pair<int, int>> chicken;
vector<pair<int, int>> home;
vector<vector<int>> dist; // 각 치킨별 집까지의 거리

void solution(vector<int> v) {
    int sum = 0;
    for(int i = 0; i < home.size(); i++) {
        int minDist = 101;
        for(int j = 0; j < v.size(); j++) {
            minDist = min(minDist, dist[v[j]][i]);
        }
        sum += minDist;
    }
    result = min(result, sum);
}

void comb(vector<int> v, int len) {
    if(len == M) {
        solution(v);
        return;
    }
    for(int i = (len == 0 ? 0 : v[len - 1] + 1); i < chicken.size(); i++) {
        vector<int> v2 = v;
        v2.push_back(i);
        comb(v2, len + 1);
    }
}

int main(void) {

    // 입력
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++) {
            cin >> map[i][j];
            if(map[i][j] == 1)
                home.push_back({i, j});
            else if(map[i][j] == 2)
                chicken.push_back({i, j});
        }

    for(int i = 0; i < chicken.size(); i++) {
        vector<int> v;
        dist.push_back(v);
        for(int j = 0; j < home.size(); j++) {
            int dy = abs(chicken[i].first - home[j].first);
            int dx = abs(chicken[i].second - home[j].second);
            dist[i].push_back(dy + dx);
        }
    }

    vector<int> v;
    comb(v, 0);
    cout << result;
}