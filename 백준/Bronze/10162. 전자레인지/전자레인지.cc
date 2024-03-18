#include <iostream>
using namespace std;

int T;
int unit[3] = {300, 60, 10};
int count[3];

int main(void){
    cin >> T;
    for(int i = 0; i < 3; i++)
        if(T >= unit[i]){
            count[i] += int(T / unit[i]);
            T = T % unit[i];
        }

    if(T == 0)
        cout << count[0] << " " << count[1] << " " << count[2];
    else
        cout << "-1";
}