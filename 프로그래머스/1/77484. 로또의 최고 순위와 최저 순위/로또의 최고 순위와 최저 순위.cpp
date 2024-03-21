#include <string>
#include <vector>
using namespace std;

bool winNums[46];
vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    int zeroCnt = 0, winCnt = 0;
    for(int n : win_nums) winNums[n] = true;
    for(int lotto : lottos) {
        if(lotto == 0) ++zeroCnt;
        else if(winNums[lotto]) ++winCnt;
    }
    return {min(7 - winCnt - zeroCnt, 6), min(7- winCnt, 6)};
}