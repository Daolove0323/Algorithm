#include <string>
#include <vector>
using namespace std;

int month[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string day[] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

string solution(int a, int b) {
    int cnt = 5;
    for(int m = 1; m <= a; ++m)
        for(int d = 1; d <= month[m - 1]; ++d) {
            if(m == a && d == b) return day[cnt % 7];
            ++cnt;
        }
}