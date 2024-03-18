#include <iostream>
using namespace std;

char S[1000000];
char c;
int zero, one;

int main(void){
    cin >> S;
    c = '\0';
    for(int i = 0; S[i] != '\0'; i++){
        if(c != S[i]){
            if(S[i] == '0'){
                zero++;
                c = '0';
            }
            else{
                one++;
                c = '1';
            }
        }
    }
    if(zero < one)
        cout << zero;
    else
        cout << one;
}