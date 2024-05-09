#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

string s, buff;
vector<string> v;
vector<int> toPlus, toMinus;
int sum;

int main() {
    cin >> s;
    for (auto& c : s)
        if (c == '-') c = ' ';
    istringstream iss(s);
    while (iss >> buff)
        v.push_back(buff);
   for (int i = 0; i < v.size(); ++i)
        for (int j = 0; j < v[i].size(); ++j)
            if (v[i][j] == '+') v[i][j] = ' ';
    iss = istringstream(v[0]);
    while (iss >> buff)
        toPlus.push_back(stoi(buff));
    for (int i = 1; i < v.size(); ++i) {
        iss = istringstream(v[i]);
        while (iss >> buff)
            toMinus.push_back(stoi(buff));
    }
    for (auto i : toPlus) sum += i;
    for (auto i : toMinus) sum -= i;
    cout << sum;
}
