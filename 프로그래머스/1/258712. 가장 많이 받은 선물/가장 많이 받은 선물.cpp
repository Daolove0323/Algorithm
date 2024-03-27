#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <iostream>
using namespace std;

int giftCount[51][51];
int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    unordered_map<string, int> um;
    vector<int> giftIndex(friends.size(), 0);
    vector<int> nextMonth(friends.size(), 0);
    
    // 이번달에 준 선물 개수 저장
    for(int i = 0; i < friends.size(); ++i) um[friends[i]] = i;
    for(string s : gifts) {
        string s1, s2;
        istringstream iss(s);
        iss >> s1 >> s2;
        ++giftCount[um[s1]][um[s2]];
    }
    
    // 선물 지수 저장
    for(int i = 0; i < friends.size(); ++i) {
        for(int j = 0; j < friends.size(); ++j) {
            giftIndex[i] += giftCount[i][j];
            giftIndex[i] -= giftCount[j][i];
        }
    }
    
    // 처리
    for(int i = 0; i < friends.size(); ++i) {
        for(int j = i + 1; j < friends.size(); ++j) {
            if(giftCount[i][j] == giftCount[j][i]) {
                if(giftIndex[i] > giftIndex[j]) ++nextMonth[i];
                else if(giftIndex[i] < giftIndex[j]) ++nextMonth[j];
            }
            else if(giftCount[i][j] > giftCount[j][i]) ++nextMonth[i];
            else ++nextMonth[j];
        }
    }
    for(int i = 0; i < friends.size(); ++i)
        answer = max(answer, nextMonth[i]);

    return answer;
}