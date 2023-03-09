#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long int;

#define fr(i,a,b) for(ll i=a;i<b;i++)

const int maxN = 2e5+7, limit = 31;

vvi adjlist(maxN);
int up[maxN][limit+1];
int parent[maxN],depth[maxN];
parent[1] = depth[1] = 1;

void dfs(int node,int par) {
	for(auto x : adjlist[node]){
		if(x == par) continue; 

		parent[x] = node;
		depth[x] = depth[node]+1;
		dfs(x,node);
	}
}

void precmp() {

	fr(i,1,n+1)
		up[i][0] = parent[i];

	fr(i,1,limit+1){
		fr(j,1,n+1){
			up[j][i] = up[up[j][i-1]][i-1];
		}
	}
}

int getKthAncestor(int node,int k) {
	if(k >= depth[node]) return -1;

	fr(i,0,limit+1){
		if(k&(1<<i))
			node = up[node][i];
	}
	return node;
}