#include <iostream>
using namespace std;

int N, M, input, maxVal;
int arr[100];

int main(void){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> input;
        arr[i] = input;
    }
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            for(int k = j + 1 ; k < N; k++){
                int sum = arr[i] + arr[j] + arr[k];
                if(maxVal < sum && sum <= M) maxVal = sum;
            }
        }
    }
    cout << maxVal;
}