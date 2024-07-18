#include <iostream>
using namespace std;

long long a, b, c, answer = 1;

int main() {
    cin >> a >> b >> c;
    while(b > 0) {
        if (b % 2 == 1)
            answer = (answer * a) % c;
        b /= 2;
        a = (a * a) % c;
    }
    cout << answer;
}