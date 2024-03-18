#include <iostream>
using namespace std;

char N[1000001];
int cnt[10];
int val, sum;

int main(void){
    cin >> N;
    for(int i = 0; N[i] != '\0'; i++){
        val = N[i] - '0';
        sum += val;
        cnt[val]++;
    }

    if(sum != 0 && sum % 3 == 0 && cnt[0] > 0)
        for(int i = 9; i >= 0; i--)
            for(int j = 0; j < cnt[i]; j++)
                cout << i;
    else
        cout << -1;
}