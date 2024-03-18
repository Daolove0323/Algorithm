#include <string>
#include <vector>
using namespace std;

string solution(vector<int> food) {
    string asc = "", des = "";
    for(int i = 1; i < food.size(); ++i)
        for(int j = 0; j < food[i] / 2; ++j)
            asc += i + '0';
    for(int i = asc.size() - 1; i >= 0; --i)
        des += asc[i];
    return asc + '0' + des;
}