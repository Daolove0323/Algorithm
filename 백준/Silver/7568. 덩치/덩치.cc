#include <iostream>
using namespace std;

int N;
int x[200], y[200], result[200];

int main(void) {
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> x[i] >> y[i];

    for(int i = 0; i < N; i++) {
        result[i] = 1;
        for(int j = 0; j < N; j++)
            if(x[i] < x[j] && y[i] < y[j])
                result[i]++;
        cout << result[i] << " ";
    }
}