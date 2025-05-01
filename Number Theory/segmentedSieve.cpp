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

const int N = 1e8;
bool sieve[N+1];

void computeSieve(int n = N) {
	for(int i=2;i<=n;i++){
		sieve[i] = true;
	}

	for(int i=2;i*i<=n;i++){
		if(sieve[i] == true){
			for(int j=i*i;j<=n;j+=i)
				sieve[j] = false;
		}
	}
}
computeSieve();

vector<int> generatePrimes(int n) {
	vector<int> primes;
	
	for(int i=2;i<=n;i++){ 
		if(sieve[i] == true) 
			primes.push_back(i);
	}
	
	return primes;
}

vector<bool> segmentedSieve(ll l,ll r){
	vector<bool> dummy(r-l+1,true);
	vector<int> primes = generatePrimes(sqrt(r));

	for(auto pr : primes) {
		ll firstMultiple = (l/pr) * pr;
		if(firstMultiple < l) firstMultiple += pr;
		
		for(ll j = max(firstMultiple,pr*pr); j<=r ; j+=pr)
			dummy[j-l] = false;
	}

	return dummy;
}


