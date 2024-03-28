#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(string s) {
    string binaryString = s;
    int loopCnt = 0, erasedCnt = 0;
    while(binaryString != "1") {
    int oneCnt = 0;
    for(char c : binaryString) if(c == '1') ++oneCnt;
        erasedCnt += binaryString.size() - oneCnt;
        binaryString = "";
        while(oneCnt > 0) {
            if(oneCnt % 2 == 1) binaryString = '1' + binaryString;
            else binaryString = '0' + binaryString;
            oneCnt /= 2;
        }
        ++loopCnt;
    }
    return {loopCnt, erasedCnt};
}