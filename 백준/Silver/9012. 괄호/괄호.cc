#include <iostream>
#include <string>
#include <vector>
using namespace std;

int T, n;
string str;

int main(void){
	cin >> T;

	while(T--){
	cin >> str;

	for(int i = 0; i < str.size(); i++)
		if(str[i] == '(')
			n++;
		else{
			n--;
			if(n < 0)
				break;
		}


	if(n == 0)
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';

	str.clear();
	n = 0;
	}
}