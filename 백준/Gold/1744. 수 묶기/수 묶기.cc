#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, input, sum;
vector<int> v;

int main(void) {
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> input;
        v.push_back(input);
    }
    
    sort(v.begin(), v.end(), greater<int>());
    for(int i = 0; i < N; i++)
        if(v[i] <= 0) {
            sort(v.begin() + i, v.end());
            break;
        }
    
    for(int i = 0; i < v.size(); i++) {

        if(i + 1 < v.size() && v[i] + v[i + 1] < v[i] * v[i + 1]){
            sum += v[i] * v[i + 1];
            i++;
        }
        else
            sum += v[i];
    }

    cout << sum;
}