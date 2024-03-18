#include <iostream>
using namespace std;

int main(void) {
    int a, b;
    cin >> a >> b;
    for(int i = 0; i < b; ++i, cout << endl)
        for(int j = 0; j < a; ++j)
            cout << '*';
}