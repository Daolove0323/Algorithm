#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end(), less<string>());
    for(int i = 0; i < phone_book.size() - 1; ++i) {
        int size = min(phone_book[i].size(), phone_book[i + 1].size());
        if(phone_book[i].substr(0, size) == phone_book[i + 1].substr(0, size))
            return false;
    }
    return true;
}