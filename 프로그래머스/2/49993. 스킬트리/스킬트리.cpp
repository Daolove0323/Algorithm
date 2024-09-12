#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    vector<bool> isSkill('Z' - 'A' + 1, false);
    map<char, int> orders;
    map<int, char> skills;
    for (int i = 0; i < skill.size(); ++i) {
        isSkill[skill[i] - 'A'] = true;
        orders[skill[i]] = i + 1;
        skills[i + 1] = skill[i];
    }
    for (auto s : skill_trees) {
        vector<bool> learned('Z' - 'A' + 1, false);
        bool success = true;
        for (auto c : s) {
            if (isSkill[c - 'A'] == false) continue;
            if (orders[c] != 1 && learned[skills[orders[c] - 1] - 'A'] == false) {
                success = false;
                break;
            }
            learned[c - 'A'] = true;
        }
        if (success) ++answer;
    }
    return answer;
}