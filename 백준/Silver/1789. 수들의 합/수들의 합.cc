#include <iostream>
using namespace std;

long cnt = 1, N;

int main(void){
    cin >> N;
    while(N >= cnt){
        N -= cnt;
        cnt++;
    }
    cout << cnt - 1;
}
