#include <iostream>
#include <cmath>
using namespace std;

int N, a[1000], b[1000];	// N : 사각형의 개수, a, b : 각 사각형의 가로, 세로를 저장할 배열
int dp[2][1000];		// dp[i][j], j - 1번째 사각형이 세워지거나(i = 0), 눕혀졌을 때(i = 1), 0 ~ (j - 1)번째 사각형까지의 최대 윗 둘레 
int h0, h1;		// 사각형의 높이를 저장할 버퍼

int main() {
	cin >> N;		// 사각형의 개수 입력
	for (int i = 0; i < N; ++i)		// 사각형의 개수 만큼
		cin >> a[i] >> b[i];		// 가로, 세로 길이 입력

	dp[0][0] = a[0], dp[1][0] = b[0];	// 0번째 사각형에 대해 처리(dp의 초기값 처리)
	h0 = b[0], h1 = a[0];

	for (int i = 1; i < N; ++i) {		// 1 ~ (N - 1)번째 사각형에 대해
		dp[0][i] = max(dp[0][i - 1] + abs(b[i] - h0) + a[i], dp[1][i - 1] + abs(b[i] - h1) + a[i]);		// 이번 사각형이 세워진 경우의 최대값 : 지난 사각형의 높이와 이번 사각형 세로의 차이 + 이번 사각형의 가로 
		dp[1][i] = max(dp[0][i - 1] + abs(a[i] - h0) + b[i], dp[1][i - 1] + abs(a[i] - h1) + b[i]);		// 이번 사각형이 누워진 경우의 최대값 : 지난 사각형의 높이와 이번 사각형 가로의 차이 + 이번 사각형의 세로
		h0 = b[i], h1 = a[i];	// 이번 사각형이 누워진 경우와 세워진 경우 높이 저장
	}

	cout << max(dp[0][N - 1], dp[1][N - 1]);		// 윗 둘레의 최대값 출력
}