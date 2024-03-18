#include <iostream>
using namespace std;

int money, count, change;
int unit[6] = {500, 100, 50, 10, 5, 1};

int main(void){
    cin >> money;
    change = 1000 - money;

    for(int i = 0; i < 6; i++)
        if(change >= unit[i]){
            count += change / unit[i];
            change = change % unit[i];
        }

    cout << count;
}