#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    unordered_map<string, int> curPos;
    for(int i = 0; i < players.size(); ++i)
        curPos[players[i]] = i;
    for(string calling : callings) {
        int ranking = curPos[calling]--;
        string front = players[ranking - 1];
        ++curPos[front];
        string tmp = players[ranking];
        players[ranking] = players[ranking - 1];
        players[ranking - 1] = tmp;
    }
    return players;
}