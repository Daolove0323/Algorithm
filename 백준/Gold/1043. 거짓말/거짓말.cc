#include <iostream>
#include <vector>
using namespace std;

const int NOT_TELL = 0;
const int TELL_TRUTH = 1;
const int LIE = 2;

int n, m, knower_cnt, knower_idx, attendee_cnt, attendee_idx, answer;
vector<vector<int>> party;

bool say(int party_idx, vector<int>& know, int what_to_say) {
    for (int idx : party[party_idx]) {
        if (know[idx] != NOT_TELL && know[idx] != what_to_say)
            return false;
        know[idx] = what_to_say;
    }
    return true;
}

void dfs(int party_idx, vector<int> know, int cnt) {
    if (party_idx >= m) {
        answer = max(answer, cnt);
        return;
    }
    vector<int> knowTruth = know;
    vector<int> knowLie = know;
    if (say(party_idx, knowTruth, TELL_TRUTH))
        dfs(party_idx + 1, knowTruth, cnt);
    if (say(party_idx, knowLie, LIE))
        dfs(party_idx + 1, knowLie, cnt + 1);
}

int main() {
    cin >> n >> m;
    cin >> knower_cnt;
    vector<int> know(n + 1, NOT_TELL);
    for (int i = 0; i < knower_cnt; ++i) {
        cin >> knower_idx;
        know[knower_idx] = TELL_TRUTH;
    }
    for (int i = 0; i < m; ++i) {
        cin >> attendee_cnt;
        party.push_back({});
        for (int j = 0; j < attendee_cnt; ++j) {
            cin >> attendee_idx;
            party[i].push_back(attendee_idx);
        }
    }
    dfs(0, know, 0);
    cout << answer;
}