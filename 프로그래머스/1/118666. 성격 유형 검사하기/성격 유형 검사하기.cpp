#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    int score[4] = {};
    for(int i = 0; i < survey.size(); ++i) {
        switch (survey[i][0]) {
            case 'R' :
                score[0] +=  choices[i] - 4;
                break;
            case 'T' :
                score[0] -=  choices[i] - 4;
                break;
            case 'C' :
                score[1] +=  choices[i] - 4;
                break;
            case 'F' :
                score[1] -=  choices[i] - 4;
                break;
            case 'J' :
                score[2] +=  choices[i] - 4;
                break;
            case 'M' :
                score[2] -=  choices[i] - 4;
                break;
            case 'A' :
                score[3] +=  choices[i] - 4;
                break;
            case 'N' :
                score[3] -=  choices[i] - 4;
                break;
            }
        }
    if(score[0] <= 0) answer += 'R';
    else answer += 'T';
    if(score[1] <= 0) answer += 'C';
    else answer += 'F';
    if(score[2] <= 0) answer += 'J';
    else answer += 'M';
    if(score[3] <= 0) answer += 'A';
    else answer += 'N';
    return answer;
}