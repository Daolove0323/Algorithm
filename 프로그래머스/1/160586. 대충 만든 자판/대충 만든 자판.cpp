#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> count(27, 101), answer(targets.size());
    for(int i = 0; i < keymap.size(); ++i)
        for(int j = 0; j < keymap[i].size(); ++j)
            count[keymap[i][j] - 'A'] = min(j + 1, count[keymap[i][j] - 'A']);
    for(int i = 0; i < targets.size(); ++i)
        for(int j = 0; j < targets[i].size(); ++j)
            if(count[targets[i][j] - 'A'] == 101) {
                answer[i] = -1;
                break;
            }
            else {
                answer[i] += count[targets[i][j] - 'A'];
            }            
    return answer;
}