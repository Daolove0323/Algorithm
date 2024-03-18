#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    int n = 0;
    for(int i = 0; i < arr.size(); ++i)
        if(arr[i] < arr[n]) n = i;
    arr.erase(arr.begin() + n);
    if(arr.empty()) arr.push_back(-1);
    return arr;
}