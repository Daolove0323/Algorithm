#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    vector<pair<int, int>> number(10);
    number[0] = {4, 2};
    pair<int, int> leftPos = {4, 1}, rightPos = {4, 3};
    int leftDistance, rightDistance, idx = 1;
    for(int i = 1; i <= 3; ++i)
        for(int j = 1; j <= 3; ++j)
            number[idx++] = {i, j};
    for(int n : numbers) {
        if(n == 1 || n == 4 || n == 7) {
            leftPos = number[n];
            answer += 'L';
        }
        else if(n == 3 || n == 6 || n == 9) {
            rightPos = number[n];
            answer += 'R';
        }
        else {
            leftDistance = abs(number[n].first - leftPos.first) + abs(number[n].second - leftPos.second);
            rightDistance = abs(number[n].first - rightPos.first) + abs(number[n].second - rightPos.second);
            if(leftDistance == rightDistance) {
                if(hand == "right") {
                    answer += 'R';
                    rightPos = number[n];
                }
                else {
                    answer += 'L';
                    leftPos = number[n];
                }
            }
            else if(leftDistance < rightDistance) {
                answer += 'L';
                leftPos = number[n];
            }
            else {
                answer += 'R';
                rightPos = number[n];
            }
        }        
    }
    return answer;
}