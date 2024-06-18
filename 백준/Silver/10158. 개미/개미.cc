#include <iostream>
using namespace std;

int myAbs(int n) {
	if (n < 0) return n * -1;
	return n;
}

int curX, curY, w, h, t;

int main() {
	cin >> w >> h >> curX >> curY >> t;
	curX = (t + curX) % (2 * w);
	if (curX >= w) curX = myAbs(curX - 2 * w);
	curY = (t + curY) % (2 * h);
	if (curY >= h) curY = myAbs(curY - 2 * h);
	cout << curX << " " << curY;
}
