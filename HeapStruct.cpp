#include <iostream>

using namespace std;

const int MAXN = 1000;

struct heap{
	int value[MAXN], size;
	
	heap(){
		size = 0;	
	}

	void down_to_up(int node){
		if(node == 1) return;
		if(value[node] < value[node / 2]){
			swap(value[node], value[node / 2]);
			down_to_up(node / 2);
		}	
	}
	
	void up_to_down(int node){
		if(node * 2 > size) return;
		else if(node * 2 + 1 > size and value[node] > value[node * 2]){
			swap(value[node], value[node * 2]);
			up_to_down(node * 2);
		}
		else if (node * 2 + 1 <= size){
			int ind = (value[node * 2] < value[node * 2 + 1]) ? (node * 2) : (node * 2 + 1);
			swap(value[node], value[ind]);
			up_to_down(ind);
		}
	}
	
	void add(int x){
		value[++size] = x;
		down_to_up(size);
	}
	
	int min(){
		return value[1];
	}
	
	void pop(){
		if(size == 0) return;
		swap(value[1], value[size]);
		
		size--;
		up_to_down(1);
	}
};

int main(){

	// test
	heap jahan;
	
	jahan.add(15);
	jahan.add(12);
	jahan.add(-2);
	cout << jahan.min() << endl;
	jahan.pop();
	jahan.add(13);
	cout << jahan.min() << endl;
	// end test

	return 0;		
}
