#include <iostream>
using namespace std;

int T, L, P, V, sum, val;

int main(void){
    while(true){
        T++;
        cin >> L >> P >> V;
        if(L == 0 && P == 0 && V == 0)
            break;

        sum = 0;
        if((V % P) < L)
            val = V % P;
        else
            val = L;
        sum += int(V / P) * L + val;
        printf("Case %d: %d\n", T, sum);
    }
}