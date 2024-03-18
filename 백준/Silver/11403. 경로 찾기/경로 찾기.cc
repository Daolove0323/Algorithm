#include <iostream>
using namespace std;

bool arr[100][100];
int N;

int main(void) {
    cin >> N;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> arr[i][j];

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(!arr[j][i]) continue;
            for(int k = 0; k < N; k++) {
                if(!arr[i][k]) continue;
                arr[j][k] = true;
            }
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}