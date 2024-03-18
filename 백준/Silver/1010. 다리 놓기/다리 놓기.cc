#include <iostream>
using namespace std;

int T, N, M;
int main(void)
{
	cin >> T;
	while(T--)
	{
		cin >> N >> M;

		unsigned long result = 1;
		int r = N < M - N ? N : M - N;
		for(int i = 0; i < r; i++)
		{
			result *= (M - i);
			result /= (i + 1);
		}

		cout << result << endl;
	}
}