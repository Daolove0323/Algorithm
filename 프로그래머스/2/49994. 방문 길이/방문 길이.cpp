#include <string>
#include <iostream>
using namespace std;

int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1}; // L, R, D, U
bool visitedX[11][10], visitedY[10][11];
int posX = 5, posY = 5, cnt = 0;

void move(int dir) {
    if(dir == 0 && posX > 0) {
        --posX;
        if(!visitedX[posY][posX]) ++cnt;
        visitedX[posY][posX] = true;
    }
    else if(dir == 1 && posX < 10) {
        if(!visitedX[posY][posX]) ++cnt;
        visitedX[posY][posX] = true;
        ++posX;
    }
    else if(dir == 2 && posY > 0) {
        --posY;
        if(!visitedY[posY][posX]) ++cnt;
        visitedY[posY][posX] = true;
    }
    else if(dir == 3 && posY < 10) {
        if(!visitedY[posY][posX]) ++cnt;
        visitedY[posY][posX] = true;
        ++posY;
    }
}

int solution(string dirs) {
    int answer = 0;
    for(char c : dirs) {
        if(c == 'L') move(0);
        else if(c == 'R') move(1);
        else if(c == 'D') move(2);
        else if(c == 'U') move(3);
    }
    return cnt;
}