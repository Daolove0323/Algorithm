#include <string>
#include <cmath>
#include <iostream>
using namespace std;

int num[4], score[4];
int solution(string dartResult) {
    int answer = 0, cur =0; bool beforeIs1 = false;
    for(char c : dartResult) {
        if('0' <=c && c <= '9') {
            if(beforeIs1) num[cur] = score[cur] = 10;
            else num[cur] = score[++cur] = c - '0';
        }
        else if(c == 'S') score[cur] = pow(score[cur], 1);
        else if(c == 'D') score[cur] = pow(score[cur], 2);
        else if(c == 'T') score[cur] = pow(score[cur], 3);
        else if(c == '*') { score[cur - 1] *= 2; score[cur] *= 2; }
        else if(c == '#') {score[cur] *= -1;}
        beforeIs1 = c == '1' ? true : false;
    }
    return score[1] + score[2] + score[3];
}