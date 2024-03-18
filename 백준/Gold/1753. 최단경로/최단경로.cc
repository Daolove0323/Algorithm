#include <iostream>
#include <vector>
#include <queue>
#define MAX	200001
#define INF 987654321
using namespace std;

struct edge{
	int vertex;
	int distance;
	edge(int v, int d) : vertex(v), distance(d) {}
	bool operator<(const edge& e) const {return distance > e.distance;}
};

int V, E, K;
vector<pair<int, int>> adj[MAX];
vector<int> distances(MAX, INF);
priority_queue<edge> pq;

void dijkstra(int k){
	distances[k] = 0;
	pq.push(edge(k, 0));

	while(!pq.empty()){
		int v = pq.top().vertex;
		int d = pq.top().distance;
		pq.pop();

		for(int i = 0; i < adj[v].size(); i++){
			int nextV = adj[v][i].first;
			int nextD = d + adj[v][i].second;
			if(distances[nextV] > nextD){
				distances[nextV] = nextD;
				pq.push(edge(nextV, nextD));
			}
		}
	}
}



int main(void){
	cin >> V >> E >> K;
	for(int i = 0, u, v, w; i < E; i++){
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
	}

	dijkstra(K);
    // for(int i=1;i<=V;i++)
    //     cout<<(distances[i]==INF?"INF":to_string(distances[i]))<<'\n';

	for(int i = 1; i <= V; i++)
		if(distances[i] == INF)
			cout << "INF" << '\n';
		else
			cout << to_string(distances[i]) << '\n';
}