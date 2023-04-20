
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using pi = pair<int,int>;
using vpi = vector<pi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pl = pair<ll,ll>;
using vpl = vector<pl>;
using vc = vector<char>;
using vvc = vector<vc>;
using vs = vector<string>;
const ll mod = 1e9 + 7,inf = 1e18;

#define endl '\n'
#define fr(k,a,b) for(ll k=a;k<b;k++)
#define rfr(k,a,b) for(ll k=a;k>=b;k--)
#define pb push_back
#define all(x) x.begin(),x.end()
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


// Find maximum length subarray whose sum is <= k
ll findMaxLenSubarray(vl &arr,ll k) {
	int n = arr.size();
	int i=0,j=0,ans=0;
	ll sum = 0;

	while(j < n) {
		sum += arr[j];

		while(i <= j and sum > k){
			sum -= arr[i++];
		}

		ans = max(ans,j-i+1);
		j++;
	}

	return ans;
}

// Find number of subarrays whose sum is <=k
ll findCountOfSubarrays(vl &arr,ll k) {
	int n = arr.size();
	int i=0,j=0,ans=0;
	ll sum = 0;

	while(j < n) {
		sum += arr[j];

		while(i <= j and sum > k){
			sum -= arr[i++];
		}

		ans += j-i+1;
		j++;
	}

	return ans;
}