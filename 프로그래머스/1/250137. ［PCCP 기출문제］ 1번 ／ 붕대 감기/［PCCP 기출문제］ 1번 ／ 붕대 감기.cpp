#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int hp = health, time = 0;
    for(auto attack : attacks) {
        int timeDiff = attack[0] - time - 1;
        time = attack[0];
        int healing = timeDiff * bandage[1] + timeDiff / bandage[0] * bandage[2];
        hp = min(health, hp + healing);
        hp -= attack[1];
        if(hp <= 0) return -1;
    }
    return hp;
}