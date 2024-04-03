#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    for(int i = 0; i < progresses.size(); ++i) {
        if((100 - progresses[i]) % speeds[i] == 0)
            progresses[i] = (100 - progresses[i]) / speeds[i];
        else
            progresses[i] = (100 - progresses[i]) / speeds[i] + 1;
    }
    for(int i = 0; i < progresses.size();) {
        int n = 1;
        for(int j = i + 1; j < progresses.size(); ++j) {
            if(progresses[i] >= progresses[j]) ++n;
            else break;
        }
        i += n;
        answer.push_back(n);
    }
    return answer;
}