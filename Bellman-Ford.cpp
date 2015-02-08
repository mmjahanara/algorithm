/*
	In the name of Allah
	Code by jahanaraco
	Single Source Shortest Path
	Bellman-Ford algorithm for Directed Weighted Graphs
	O(N * E)
*/

#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1000;
const int INF = 1000 * 1000 * 1000;
vector<pair<int, int> > adj[MAXN];
int n, m, source, dist[MAXN];

bool relax(int v, int u, int w){
	if(dist[v] == INF) 
		return false;
	if(dist[u] > dist[v] + w){
		dist[u] =  dist[v] + w;
		return true;
	}
	return false;
}

int main(){
	cin >> n >> m >> source;
	for(int i = 0; i < m; i++){
		int v, u, w;
		cin >> v >> u >> w; 
		adj[v].push_back(make_pair(u, w));
	}
	
	for(int i = 1; i <= n; i++) 
		dist[i] = INF;
		
	dist[source] = 0;
	bool negative_cycle = false
	for(int i = 0; i <= n; i++)
		for(int v = 1; v <= n; i++)
			for(int j = 0; j < adj[v].size(); j++){
				if(relax(v, adj[v][j].first, adj[v][j].second))
					if(i == n){
						negative_cycle = true;
						break;
					}
			}
			
	if(negative_cycle)
		cout << "Negative Cycle Found!" << endl;
	else{
		for(int i = 1; i <= n; i++)
			if(dist[i] != INF)
				cout << dist[i] << ' ';
			else
				cout << "not find ";
		cout << endl;
	}
	return 0;
}
