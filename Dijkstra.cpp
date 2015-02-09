/*
	In the name of Allah
	Code by jahanaraco
	Single Source Shortest Path
	Dijkstras algorithm for Weighted Graphs
	O(N lg E)
*/

#include <iostream>
#include <set>
#include <vector>

using namespace std;

const int MAXN = 1000 * 100;
int n, m, source, dist[MAXN];
vector<pair<int, int> > adj[MAXN];
set<pair<int, int> > S; // Set of candidates vertices

int parent[MAXN]; // "parent[i] = v" means v is last vertex updated i 
void print_path(int v);

int main(){
	cin >> n >> m >> source; 
	for(int i = 0; i < m; i++){
		int v, u, w;
		cin >> v >> u >> w;
		adj[v].push_back(make_pair(u, w));
		adj[u].push_back(make_pair(v, w));
	}
	
	for(int i = 1; i <= n; i++)
		dist[i] = -1; // -1 means there's no path yet
	
	dist[source] = 0;
	S.insert(make_pair(0, source));
	while(!S.empty() /*S.size() > 0 */){
		int v = S.begin() -> second;
		// int v = (*S.begin()).second;
		S.erase(S.begin());
		for(int i = 0; i < adj[v].size(); i++){
			int u = adj[v][i].first;
			int w = adj[v][i].second;
			if(dist[u] == -1 or dist[u] > dist[v] + w){
				if(dist[u] != -1) 
					S.erase(make_pair(dist[u], u));
				dist[u] = dist[v] + w;
				S.insert(make_pair(dist[u], u));
				parent[u] = v; // note this line
			}
		}
	}	
	
	/* 	// print shortest path for every i
		for(int i = 1; i <= n; i++){
			if(dist[i] != -1){
				print_path(i);
				cout << endl;
			}
			else
				cout << -1 << endl;
		}
	*/
	
	for(int i = 1; i <= n; i++)
		cout << dist[i] << ' ' ;
	cout << endl;
	return 0;
}

void print_path(int v){
	if(parent[v] != 0)
		print_path(parent[v]);
	cout << v << ' ';
}
