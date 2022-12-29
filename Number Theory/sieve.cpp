// Time complexity -> O(Nlog(logN))

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
#define fr(a,b) for(int i=0;i<b;i++)

int N = 2e5;
vb sieve(N+1);

void computeSieve(int n) {
	fr(0,n+1) sieve[i] = true;

	for(int i=2;i*i <=n;i++){
		if(sieve[i] == false) continue;
		for(int j=i*i;j<=n;j+=i){
			sieve[j] = false;
		}
	} 
}

vi getPrimes(int n) {
	computeSieve(n);
	vi primes;

	fr(2,n+1) 
		if(sieve[i]) primes.pb(i);
	return primes;
}








