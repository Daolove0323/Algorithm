#include <iostream>
using namespace std;

int T, N, count, document, interview, minimum;
int score[100001];

int main(void){
    cin >> T;
    while(T--){
        cin >> N;
        for(int i = 0; i < N; i++){
            cin >> document >> interview;
            score[document] = interview;
        }
        count = 0, minimum = 100001;
        for(int i = 1; i <= N; i++){
            if(score[i] < minimum){
                count++;
                minimum = score[i];
                }
        }
        cout << count << '\n';
    }
}