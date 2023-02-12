#include<bits/stdc++.h>
using namespace std;

using ll = long long int;
using vl = vector<ll>;
#define fr(k,a,b) for(ll k=a;k<b;k++)

class FenwickTreeRangeUpdatePointQuery{
private:
	int N;
	vl tree;

	int lsb(int i){
		return (i & -i);
	}
public:
	FenwickTreeRangeUpdatePointQuery(int n) {
		N = n;
		tree.resize(N+1,0);
	}

//  Construction of fenwick tree, O(n)
	FenwickTreeRangeUpdatePointQuery(vl &arr){
		N = arr.size();
		tree.resize(N+1,0);

		fr(i,1,N+1){
			tree[i] += arr[i-1];
			if(i + lsb(i) <= N) tree[i+lsb(i)] += tree[i];
		}
	}

//  Returns the prefix sum from [1, i], O(log(n))
	ll prefixSum(int i){
		ll sum = 0;
		while(i){
			sum += tree[i];
			i &= ~lsb(i); // Equivalently, i -= lsb(i);
		} 
		return sum;
	}

//  Returns the value at index 'i', O(1)
	ll pointQuery(int i){
		return prefixSum(i);
	} 

//  Add 'delta' to index 'i', O(log(n))
	void pointUpdate(int i,ll delta){
		while(i <= N){
			tree[i] += delta;
			i += lsb(i);
		}
	}

//  O(log n)
	void rangeUpdate(int l,int r,ll delta){
		pointUpdate(l,delta);
		pointUpdate(r+1,-delta);
	}
};