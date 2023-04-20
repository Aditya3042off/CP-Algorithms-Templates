
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vc = vector<char>;
using vvc = vector<vc>;
using vs = vector<string>;
const ll mod = 1e9 + 7,inf = 1e18;

#define pb push_back
#define fr(k,a,b) for(ll k=a;k<b;k++)
#define rfr(k,a,b) for(ll k=a;k>=b;k--)
#define raf(k,container) for(auto &k : container)


// Time complexity -> O(sqrt(N))
// Not suitable when queries are given
map<int,int> primeFactorsWithPowers(int n) {
	map<int,int> pf;

	for(int i=2;i*i<=n;i++) {
		while(n % i == 0){
			pf[i]++;
			n /= i;
		}
	}
	if(n > 1) pf[n]++;

	return pf;
}

// Time Complexity -> O(N log(logN) + Q*logN)
// Suitable when queries are given

int N = 2e5;
vi spf(N+10);

void createSPF(int n = N) {
	fr(i,1,n+1) spf[i] = i;

	for(int i=2;i*i<=n;i++){
		if(spf[i] == i) {
			for(int j=i*i;j<=n;j+=i){
				if(spf[j] == j)
					spf[j] = i;
			}
		}
	}
}





