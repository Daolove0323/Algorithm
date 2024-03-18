#include <iostream>
#include <queue>
using namespace std;

int N, card, total, sum;
priority_queue<int, vector<int>, greater<int>> pq;

int main(void){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &card);
        pq.push(card);
    }
    
    while(pq.size() > 1){
        sum = pq.top();
        pq.pop();
        sum += pq.top();
        pq.pop();
        pq.push(sum);
        total = total + sum;
    }

    printf("%d", total);
}