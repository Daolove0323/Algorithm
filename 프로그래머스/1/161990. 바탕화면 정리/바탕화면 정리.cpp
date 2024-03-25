#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    int left= 51, right =-1, top = 51, bottom = -1;
    for(int i = 0; i < wallpaper.size(); ++i) {
        for(int j = 0; j < wallpaper[0].size(); ++j) {
            if(wallpaper[i][j] == '#') {
                if(top == 51) top = i;
                bottom = i;
                left = min(left, j);
                right = max(right, j);
            }
        }
    }
    return {top, left, bottom + 1, right + 1};
}