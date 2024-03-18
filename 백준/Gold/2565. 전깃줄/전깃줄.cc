#include <iostream>
using namespace std;

int main(void)
{
	int N;
	int aData[101];
	int bData[101];


	cin>>N;
	int a, b;
	for(int i = 1; i <= N; i++)
	{
		cin>>a>>b;
		aData[i] = a;
		bData[i] = b;	
	}

	int tmp;
	for(int i = 1; i < N; i++)
	{
		for(int j = 1; j < N; j++)
		{
			if(aData[j] > aData[j+1])
			{
				tmp = aData[j];
				aData[j] = aData[j+1];
				aData[j+1] = tmp;
				
				tmp = bData[j];
				bData[j] = bData[j+1];
				bData[j+1] = tmp;
			}
		}
	}

	int ascendingArr[101] = {0, 1,};

	for(int i = 2; i <= N; i++)
	{
		for(int j = 1; j < i; j++)
		{
			if(bData[i] > bData[j] && ascendingArr[j] >= ascendingArr[i])
					ascendingArr[i] = ascendingArr[j] + 1;
		}
		if(ascendingArr[i] == 0)
			ascendingArr[i] = 1;
	}

	// for(int i = 1; i <= N; i++)
	// 	cout<<bData[i]<<" ";
	// cout<<endl;
	// for(int i = 1; i <= N; i++)
	// 	cout<<ascendingArr[i]<<" ";
	// cout<<endl;
	
	int max = 0;
	for(int i = 1; i <= N; i++)
	{
		if(ascendingArr[i] > max)
			max = ascendingArr[i];
	}

	cout<<N-max;
}