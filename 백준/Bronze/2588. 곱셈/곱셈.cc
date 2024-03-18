#include <iostream>
using namespace std;

int main(void)
{
	int num1, num2;
	cin>>num1>>num2;
	
	int first = num2 % 10;
	int second = (num2 / 10) % 10;
	int third = num2 / 100;

	cout<<num1 * first<<endl<<num1 * second<<endl<<num1 * third<<endl<<num1 * num2;
}