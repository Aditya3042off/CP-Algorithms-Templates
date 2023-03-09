#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long int;

#define fr(i,a,b) for(ll i=a;i<b;i++)

const int maxN = 2e5+7, limit = 31;

vvi adjlist(maxN);
int up[maxN][limit+1];
vi parent(maxN), depth(maxN);
depth[1] = partent[1] = 1;

void dfs(int node,int par){
	for(auto adj : adjlist[node]){
		if(adj == par) continue;

		depth[adj] = depth[node]+1;
		parent[adj] = node;
		dfs(adj,node);
	}
}

void precmp(){

	fr(i,1,n+1)
		up[i][0] = parent[i];

	fr(i,1,limit+1){
		fr(j,1,n+1){
			up[j][i] = up[ up[j][i-1] ][i-1];
		}
	}
}

int get_lca(int a,int b){
	if(depth[a] < depth[b]) swap(a,b);

	int k = depth[a]-depth[b];

	fr(i,0,limit+1){
		if(k&(1<<i)) a = up[a][i];
	}

	if(a==b) return a;

	rfr(i,limit,0){
		if(up[a][i] != up[b][i]){
			a = up[a][i];
			b = up[b][i];
		}
	}

	return a;
}