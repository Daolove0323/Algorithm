#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0, front = 0, rear = people.size() - 1;
    sort(people.begin(), people.end(), greater<int>());
    for(; front <= rear; ++front) {
        if(people[front] + people[rear] <= limit) --rear;
        ++answer;
    }
    return answer;
}