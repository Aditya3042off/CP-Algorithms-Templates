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
#define fr(a,b) for(int i=a;i<b;i++)

int N = 2e5;
vb sieve(N+1);

void computeSieve(int n = N) {
	fr(2,n) sieve[i] = true;

	for(int i=2;i*i<=n;i++){
		if(sieve[i]){
			for(int j=i*i;j<=n;j+=i)
				sieve[j] = false;
		}
	}
}

vi getPrimes(int n) {
	vi primes;
	fr(2,n+1) 
		if(sieve[i]) primes.pb(i);
	return primes;
}

vb segmentedSieve(ll l,ll r){
	vb dummy(r-l+1,true);
	vi primes = getPrimes(sqrt(r));

	for(auto pr : primes) {
		ll start = max(pr*pr*1LL,(ll) ceil(l/(pr*1.0))*pr*1LL);
		for(ll j = start;j<=r;j+=pr)
			dummy[j-l] = false;
	}

	return dummy;
}


