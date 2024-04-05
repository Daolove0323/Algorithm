#include <string>
#include <vector>
#include <iostream>
using namespace std;

int count = 0;
void bf(int k, vector<vector<int>>& dungeons, vector<bool> visited) {
    bool finished = true;
    for(int i = 0; i < dungeons.size(); ++i) {
        if(!visited[i] && dungeons[i][0] <= k) {
            vector<bool> v = visited;
            v[i] = true;
            bf(k - dungeons[i][1], dungeons, v);
            finished = false;
        }
    }
    int cnt = 0;
    if(finished)
        for(auto v : visited) if(v) ++cnt;
    count = max(count, cnt);
}
int solution(int k, vector<vector<int>> dungeons) {
    vector<bool> v(dungeons.size(), false);
    bf(k, dungeons, v);
    return count;
}