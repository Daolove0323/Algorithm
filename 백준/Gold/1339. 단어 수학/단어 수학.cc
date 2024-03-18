#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int N, sum, len;
int num = 9;
int alphabet[26];
char input[9];
priority_queue<int> pq;

int main(void){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> input;
        
        len = 0;
        for(int j = 0; input[j] != '\0'; j++)
            len++;
        
        for(int k = len, l = 0; k > 0; k--, l++)
            alphabet[input[l] - 'A'] += int(pow(10, k - 1));
    }

    for(int i = 0; i < 26; i++)
        if(alphabet[i] != 0)
            pq.push(alphabet[i]);

    while(!pq.empty()){
        int add = pq.top() * num--;
        pq.pop();
        sum += add;
    }

    cout << sum;
}