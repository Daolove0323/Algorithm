#include <iostream>
#include <cstring>>
using namespace std;

int x;
int arr[1000001];

void recursive(int num){
    if(num == 1) return;
    if(num % 2 == 0 && arr[num / 2] > arr[num] + 1){
        arr[num / 2] = arr[num] + 1;
        recursive(num / 2);
    }
    if(num % 3 == 0 && arr[num / 3] > arr[num] + 1){
        arr[num / 3] = arr[num] + 1;
        recursive(num / 3);
    }
    if(arr[num - 1] > arr[num] + 1){
    arr[num - 1] = arr[num] + 1;
    recursive(num - 1);
    }
}

int main(void){
    cin >> x;
    memset(arr, 1000000, sizeof(arr));
    arr[x] = 0;
    recursive(x);
    cout << arr[1];
}