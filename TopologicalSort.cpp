/*
	Topological Sort, DFS method
	Ali and Koosha, You should prove correctness of this algorithm for next session :D :)
*/

#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1000 * 100;
vector<int> adj[MAXN], ans;
bool mark[MAXN];
int n, m, in_degree[MAXN];

void dfs(int v);
bool check_valid();

int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		int u, v;
		adj[u].push_back(v);
		in_degree[v]++;
	}
	
	for(int i = 1; i <= n; i++)
		if(!mark[i])
			dfs(i);
	
	if(check_valid()){
		for(int i = 0; i < ans.size(); i++)
			cout << ans[i] << ' ';
		cout << endl;
	}
	else
		cout << "There's no topological sort !" 		
	return 0;
}

void dfs(int v){
	mark[v] = true;
	
	for(int i = 0; i < adj[v].size(); i++){
		int u = adj[v][i];
		if(!mark[u])
			dfs(u);
	}
	
	ans.push_back(v);
}

bool check_valid(){
	for(int i = 0; i < ans.size(); i++){
		int v = ans[i];
		if(in_degree[v] != 0)
			return false;
		for(int j = 0; j < adj[v].size(); j++){
			int u = adj[v][j];
			in_degree[u]--;
		}
	}
	return true;
}
