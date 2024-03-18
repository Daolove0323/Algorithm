#include <iostream>
using namespace std;

int N, recursive, dynamic;
int dp[41] = {1, 1};
void fib(int n){
    if(n == 1 || n == 2) recursive++;
    else{
        fib(n - 1);
        fib(n - 2);
    }
}

void fibonacci(int n){
    for(int i = 3; i <= n; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
        dynamic++;
    }
}

int main(void){
    cin >> N;
    fib(N);
    fibonacci(N);
    cout << recursive << " " << dynamic;
}