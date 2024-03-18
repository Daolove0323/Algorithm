#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int N, cnt;
int arr[25][25];
vector<int> v;

void bfs(int i, int j)
{
	queue<pair<int, int>> q;
	pair<int, int> p = make_pair(i, j);
	q.push(p);
	arr[i][j] = 0;
	cnt = 1;	
	while(!q.empty())
	{
		p = q.front();
		q.pop();
		for(int i = 0; i < 4; i++)
		{
			if(arr[p.first + dx[i]][p.second + dy[i]] == 0 || p.first + dx[i] < 0 || N <= p.first + dx[i] || p.second + dy[i] < 0 || N <= p.second + dy[i])	continue;
			arr[p.first + dx[i]][p.second + dy[i]] = 0;
			cnt++;
			q.push(make_pair(p.first + dx[i], p.second + dy[i]));
		}
	}
	v.push_back(cnt);
}

int main(void)
{
	// 입력
	cin >> N;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			scanf("%1d", &arr[i][j]);
		
	// bfs
	for(int i = 0;  i< N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(arr[i][j] == 1)
				bfs(i, j);
		}
	}

	// 출력
	sort(v.begin(), v.end());
	cout << v.size() << endl;
	for(int i = 0; i < v.size(); i++)
		cout << v[i] << endl;

}