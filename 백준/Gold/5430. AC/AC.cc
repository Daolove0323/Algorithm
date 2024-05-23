#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        string insts, data, buf;
        int n, start, end;
        vector<int> nums;
        bool forward = true;
        
        cin >> insts;   // 입력
        cin >> n;
        cin >> data;
        
        for (auto& c : data)    // 파싱하여 벡터에 숫자 삽입
            if (!isdigit(c)) c = ' ';
        istringstream iss(data);
        while (iss >> buf)
            nums.push_back(stoi(buf));
        
        start = 0; end = n - 1; // 명령어 처리
        for (auto c : insts) {
            if (c == 'D') {
                if (forward) ++start;
                else --end;
                --n;
            } else if( c == 'R')
                forward = !forward;
        }
        
        if (n < 0) { // 출력
            cout << "error" << '\n';
        } else if (n == 0) {
            cout << "[]" << '\n';
        } else {
            if (forward) {
                cout << '[';
                for (int i = start; i < end; ++i)
                    cout << nums[i] << ",";
                cout << nums[end] << "]\n";
            } else {
                cout << '[';
                for (int i = end; i > start; --i)
                    cout << nums[i] << ",";
                cout << nums[start] << "]\n";
            }
        }
    }
}