#include <iostream>
#include <algorithm>
using namespace std;

int N, result;
int w[100000];

int main(void){
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> w[i];

    sort(w, w + N, greater<>());
    for(int i = 0; i < N; i++){
        if((i + 1) * w[i] > result)
            result = (i + 1) * w[i];
    }

    cout << result;
}