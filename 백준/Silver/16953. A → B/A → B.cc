#include <iostream>
using namespace std;

int A, B, cnt;
bool success;

int main(void){
    cin >> A >> B;
    while(B >= A){
        if(A == B){
            success = true;
            break;
        }
        
        if(B % 10 == 1)
            B = (B - 1) / 10;
        else if(B % 2 == 0)
            B /= 2;
        else
            break;
        cnt++;
        

    }
    if(success)
        cout << cnt + 1;
    else
        cout << -1;
}