#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

int dy[4] = {0, 0, 1, -1}, dx[4] = {1, -1, 0, 0};
unordered_map<char, int> direction;
pair<int, int> curPos;

vector<int> solution(vector<string> park, vector<string> routes) {
    direction['E'] = 0, direction['W'] = 1, direction['S'] = 2, direction['N'] = 3;
    for(int i = 0; i < park.size(); ++i)
        for(int j = 0; j < park[i].size(); ++j)
            if(park[i][j] == 'S') {
                curPos = {i, j};
                park[i][j] = 'O';
            }
    for(string route : routes) {
        int ny = curPos.first;
        int nx = curPos.second;
        bool canMove = true;
        for(int i = 0; i < route.back() - '0'; ++i) {   
            ny += dy[direction[route.front()]];
            nx += dx[direction[route.front()]];
            if(park.size() <= ny || ny < 0 || park[0].size() <= nx || nx < 0
              || park[ny][nx] == 'X') {canMove = false; break;};
        }
        if(canMove) {
            curPos.first = ny;
            curPos.second = nx;         
        }
    }
    return {curPos.first, curPos.second};
}