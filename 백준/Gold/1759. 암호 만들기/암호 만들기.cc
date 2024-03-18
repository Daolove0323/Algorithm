#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int L, C;
char input;
vector<char> alphabet;

void combination(string s, int startIdx, int vowel, int consonant){
    if(s.size() == L) {
        if(vowel >= 1 && consonant >= 2) cout << s << endl;
        return;
    }
    
    for(int i =startIdx; i < alphabet.size(); i++) {
        string s2 = s;
        char c = alphabet[i];
        s2.push_back(c);
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            combination(s2, i + 1, vowel + 1, consonant);
        else
            combination(s2, i + 1, vowel, consonant + 1);
    }

    
}

int main(void) {
    cin >> L >> C;
    for(int i = 0; i < C; i++) {
        cin >> input;
        alphabet.push_back(input);
    }
    sort(alphabet.begin(), alphabet.end());
    string s = "";
    combination(s, 0, 0, 0);
}