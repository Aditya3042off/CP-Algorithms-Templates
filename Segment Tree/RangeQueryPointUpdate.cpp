// https://www.youtube.com/watch?v=2FShdqn-Oz8
#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
using vl = vector<ll>;

#define pb push_back
#define fr(i,a,b) for(ll i=a;i<b;i++)

// 0-based indexing for array and 1-based indexing for tree
class Sgtree{
private:
	vl tree,lazy;
	int _n;
public:
	Sgtree(vl& arr){
		_n = arr.size();
		// increasing size of array untill it becomes power of 2
		while((_n&(_n-1)) != 0) {
			arr.pb(0ll);
			_n++;
		}

		tree.resize(2*_n);
		lazy.resize(2*_n);

		// building tree iterative, O(N)
		fr(i,0,_n)
			tree[_n+i] = arr[i];
		
		for(int i=_n-1;i>=1;--i) 
			tree[i] = tree[2*i] + tree[2*i+1];
		
	}

	// recursive version, O(logN)
	ll query(ll node,ll nl,ll nr,ll ql,ll qr) {
		// lazy update
		if(lazy[node] != 0) {
			tree[node] += (nr-nl+1)*lazy[node];

			if(nl != nr) {
				lazy[2*node] += lazy[node];
				lazy[2*node+1] += lazy[node];
			}
			lazy[node] = 0;
		}

		if(nr < ql or qr < nl) return 0;
		if(nl >= ql and nr <= qr) return tree[node];

		ll mid = (nl+nr) >> 1;
		ll left_ans = query(2*node,nl,mid,ql,qr);
		ll right_ans = query(2*node+1,mid+1,nr,ql,qr);
		return left_ans + right_ans;
	}

	// recursive version, O(logN)
	void update(ll node,ll nl,ll nr,ll ql,ll qr,ll val){
		// lazy update
		if(lazy[node] != 0) {
			tree[node] += (nr-nl+1)*lazy[node];

			if(nl != nr) {
				lazy[2*node] += lazy[node];
				lazy[2*node+1] += lazy[node];
			}
			lazy[node] = 0;
		}

		if(nr < ql or qr < nl) return;

		if(nl >= ql and nr <= qr) {
			tree[node] += (nr-nl+1)*val;

			if(nl != nr) {
				lazy[2*node] += val;
				lazy[2*node+1] += val;
			}
			return;
		}

		ll mid = (nl+nr) >> 1;
		update(2*node,nl,mid,ql,qr,val);
		update(2*node+1,mid+1,nr,ql,qr,val);
		tree[node] = tree[2*node] + tree[2*node+1];
	}

	// iterative version, O(logN)
	void point_update_itr(ll i,ll val) {
		tree[_n+i] = val;

		for(int j = (_n + i) / 2; j>=1; j /= 2)
			tree[j] = tree[j*2] + tree[j*2+1];	
	}
};