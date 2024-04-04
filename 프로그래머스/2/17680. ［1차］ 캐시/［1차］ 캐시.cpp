#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0, queueSize = 0;
    unordered_map<string, int> um;
    queue<string> q;
    if(cacheSize == 0) return cities.size() * 5;
    for(string& city : cities) {
        for(auto& c : city) c = toupper(c); 
        if(queueSize < cacheSize) {
            if(um[city] == 0) { q.push(city); um[city] = 1; ++queueSize; answer += 5; }
            else { q.push(city); ++um[city]; answer += 1; }
            continue;
        }
        if(um[city] == 0) {
            q.push(city);
            um[city] = 1;
            while(!q.empty() && um[q.front()] != 1) { --um[q.front()]; q.pop();}
            --um[q.front()]; q.pop();
            answer += 5;
        }
        else { q.push(city); ++um[city]; answer += 1; }
    }
    return answer;
}