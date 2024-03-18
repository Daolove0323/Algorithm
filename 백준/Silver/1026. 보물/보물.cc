#include <iostream>
using namespace std;

int N, sum;
int a[50], b[50];

void sort(int a[]){
    for(int i = 0; i < N - 1; i++){
        for(int j = 0; j < N - 1; j++){
            if(a[j] > a[j+1]){
                int tmp = a[j+1];
                a[j+1] = a[j];
                a[j] = tmp;
            }
        }
    }
}

int main(void){
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> a[i];
    for(int i = 0; i < N; i++)
        cin >> b[i];
    
    sort(a);
    sort(b);

    for(int i = 0; i < N; i++)
        sum += a[i] * b[N-i-1];

    cout << sum;
}