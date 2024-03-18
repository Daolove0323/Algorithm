#include <iostream>
using namespace std;

void ascendingMaxVal(const int* inputArr, int* maxValArr, int arrSize)
{
	int max, maxIdx;
	maxValArr[0] = 1;
	for(int i = 1; i < arrSize; i++)
	{
		max = -1, maxIdx = -1;
		for(int j = i-1; j >= 0; j--)
		{
			if(inputArr[j] < inputArr[i] && max < maxValArr[j])
				{
					max = maxValArr[j];
					maxIdx = j;
				}
		}
		if(maxIdx != -1)
			maxValArr[i] = maxValArr[maxIdx] + 1;
		else
		maxValArr[i] = 1;
	}
}

void descendingMaxVal(const int* inputArr, int* maxValArr, int arrSize)
{
	int max, maxIdx;
	maxValArr[arrSize-1] = 1;
	for(int i = arrSize-2; i >= 0; i--)
	{
		max = -1, maxIdx = -1;
		for(int j = i+1; j <= arrSize-1; j++)
		{
			if(inputArr[j] < inputArr[i] && max < maxValArr[j])
				{
					max = maxValArr[j];
					maxIdx = j;
				}
		}
		if(maxIdx != -1)
			maxValArr[i] = maxValArr[maxIdx] + 1;
		else
			maxValArr[i] = 1;
	}
}

int returnMaxVal(const int* inputArr, int arrSize)
{
	int maxLen = 0;
	int* ascendingMaxValArr = new int[arrSize];
	int* descendingMaxValArr = new int[arrSize];
	ascendingMaxVal(inputArr, ascendingMaxValArr, arrSize);
	descendingMaxVal(inputArr, descendingMaxValArr, arrSize);

	// for(int i = 0 ; i<arrSize; i++)
	// 	cout<<ascendingMaxValArr[i]<<" ";
	// cout<<endl;

	// for(int i = 0 ; i<arrSize; i++)
	// 	cout<<descendingMaxValArr[i]<<" ";
	// cout<<endl;

	for(int i = 0; i < arrSize; i++)
	{
		for(int j = i+1; j < arrSize; j++)
		{
			if(inputArr[j] < inputArr[i] && ascendingMaxValArr[i] + descendingMaxValArr[j] > maxLen)
				maxLen = ascendingMaxValArr[i] + descendingMaxValArr[j];			
		}
		if(maxLen < ascendingMaxValArr[i])
			maxLen = ascendingMaxValArr[i];
	}

	delete []ascendingMaxValArr;
	delete []descendingMaxValArr;
	return maxLen;
}

int main(void)
{
	int N;
	cin>>N;

	int* inputArr = new int[N];
	for(int i = 0; i < N; i++)
		cin>>inputArr[i];

	cout<<returnMaxVal(inputArr, N)<<endl;
}