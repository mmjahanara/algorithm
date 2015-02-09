/*
	Longest Increasing Subsquence
	O(n lg n)
	Ali and Koosha, this code just find size of LIS, write a code to find LIS it self
*/

#include <iostream>
#include <algorithm>

using namespace std;

/* 
#define MAXN (1000 * 100)
#define INF (1000 * 1000 * 1000 + 1)
*/

const int MAXN = 1000 * 100;
const int INF = 1000 * 1000 * 1000 + 1;

int arr[MAXN], best[MAXN];

int main(){

	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
		
	for(int i = 0; i <= n; i++) best[i] = INF;
	for(int i = 0; i < n; i++){
		int ind = upper_bound(best + 1, best + n + 1, arr[i]) - best;
		best[ind] = arr[i];
	}
	
	int size = 1;
	while(best[size + 1] < INF) size++;
	cout << size << endl;
	
	return 0;
}
