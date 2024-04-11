#include <string>
#include <vector>
#include <iostream>
using namespace std;

char arr[6] = {'A', 'B', 'C', 'D', 'E', 'F'};

string solution(int n, int t, int m, int p) {
    string answer;
    string s = "0";
    int cnt = 1;
    while(s.size() < t * m) {
        string tmp;
        int num = cnt;
        while(num > 0) {
            if(num % n >= 10) tmp = arr[num % n - 10] + tmp;
            else tmp = to_string(num % n) + tmp;
            num /= n;
        }
        s += tmp;
        cnt++;
    }
    cout << s;
    for(int i = p - 1; answer.size() < t; i += m)
        answer += s[i];
    return answer;
}